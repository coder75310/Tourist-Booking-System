#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

struct Trip {
    int tripID;
    string destination;
    string date;
    float price;
};

class TripBookingSystem {
private:
    vector<Trip> availableTrips;
    vector<Trip> bookedTrips;
    int nextTripID;

public:
    TripBookingSystem() {
        nextTripID = 1;
        initializeTrips();
    }

    void initializeTrips() {
        availableTrips.push_back({nextTripID++, "Paris", "2024-09-15", 1200.50});
        availableTrips.push_back({nextTripID++, "New York", "2024-10-01", 1500.00});
        availableTrips.push_back({nextTripID++, "Tokyo", "2024-11-12", 1800.75});
    }

    void displayAvailableTrips() {
        cout << "Available Trips:\n";
        for (const auto& trip : availableTrips) {
            cout << "Trip ID: " << trip.tripID
                 << ", Destination: " << trip.destination
                 << ", Date: " << trip.date
                 << ", Price: $" << trip.price << endl;
        }
    }

    void bookTrip() {
        int tripID;
        cout << "Enter the Trip ID you want to book: ";
        cin >> tripID;

        for (auto it = availableTrips.begin(); it != availableTrips.end(); ++it) {
            if (it->tripID == tripID) {
                bookedTrips.push_back(*it);
                availableTrips.erase(it);
                cout << "Trip booked successfully!\n";
                return;
            }
        }

        cout << "Invalid Trip ID. Please try again.\n";
    }

    void viewBookedTrips() {
        if (bookedTrips.empty()) {
            cout << "No trips booked yet.\n";
        } else {
            cout << "Your Booked Trips:\n";
            for (const auto& trip : bookedTrips) {
                cout << "Trip ID: " << trip.tripID
                     << ", Destination: " << trip.destination
                     << ", Date: " << trip.date
                     << ", Price: $" << trip.price << endl;
            }
        }
    }

    void run() {
        while (true) {
            cout << "\n1. View Available Trips\n"
                 << "2. Book a Trip\n"
                 << "3. View Booked Trips\n"
                 << "4. Exit\n"
                 << "Enter your choice: ";
            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    displayAvailableTrips();
                    break;
                case 2:
                    bookTrip();
                    break;
                case 3:
                    viewBookedTrips();
                    break;
                case 4:
                    cout << "Exiting the system. Goodbye!\n";
                    exit(0);
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }
    }
};

int main() {
    TripBookingSystem system;
    system.run();
    return 0;
}
