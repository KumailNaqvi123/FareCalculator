#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time

using namespace std;

// Constants for fare calculation
const double BASE_FARE = 3.0;
const double COST_PER_KM = 1.5;
const double COST_PER_MIN = 0.25;
const double NIGHT_SURCHARGE = 2.0;
const double TRAFFIC_DELAY_SURCHARGE = 1.0;

// List of destinations
const char* destinations[] = {"Saddar", "I-14", "Chakri road", "Dhamial camp", "Harley street"};
const int numDestinations = sizeof(destinations) / sizeof(destinations[0]);

// Function to generate random distances for destinations
void generateDistances(double distances[]) {
    for (int i = 0; i < numDestinations; ++i) {
        distances[i] = 1 + rand() % 20; // Random distance between 1 and 20 km
    }
}

// Function to calculate the fare
double calculateFare(double distance, int time, bool isNight, bool hasTrafficDelay) {
    double fare = BASE_FARE;
    fare += distance * COST_PER_KM;
    fare += time * COST_PER_MIN;
    if (isNight) {
        fare += NIGHT_SURCHARGE;
    }
    if (hasTrafficDelay) {
        fare += TRAFFIC_DELAY_SURCHARGE;
    }
    return fare;
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    // Generate random distances for destinations
    double distances[numDestinations];
    generateDistances(distances);

    // Display the list of destinations
    cout << "Destinations:\n";
    for (int i = 0; i < numDestinations; ++i) {
        cout << i + 1 << ". " << destinations[i] << " (" << distances[i] << " km)\n";
    }

    // Get user's choice
    int choice;
    while (true) {
        cout << "Where would you like to go?: ";
        cin >> choice;

        // Validate the choice
        if (choice >= 1 && choice <= numDestinations) {
            break;
        } else {
            cout << "Invalid choice. Please enter a number between 1 and " << numDestinations << ".\n";
        }
    }

    // Get the selected destination's distance
    double distance = distances[choice - 1];

    // Generate random trip details
    int time = 5 + rand() % 56; // Random time between 5 and 60 minutes
    bool isNight = rand() % 2; // Randomly determine if it is night time (50% chance)
    bool hasTrafficDelay = rand() % 2; // Randomly determine if there is a traffic delay (50% chance)

    // Calculate the fare
    double fare = calculateFare(distance, time, isNight, hasTrafficDelay);

    // Output the trip details and the calculated fare
    cout << "Trip Details:\n";
    cout << "Destination: " << destinations[choice - 1] << "\n";
    cout << "Distance: " << distance << " km\n";
    cout << "Time: " << time << " minutes\n";
    cout << "Night time: " << (isNight ? "Yes" : "No") << "\n";
    cout << "Traffic delay: " << (hasTrafficDelay ? "Yes" : "No") << "\n";
    cout << "Total Fare: $" << fare << "\n";

    return 0;
}
