#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Vehicle {
    string vehicleNumber;
    string vehicleType;
    string vehicleName;
    string ownerName;
};

vector<Vehicle> parkedVehicles;
int bikes = 100, cars = 250, bicycles = 78;

int getIntegerInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
            return value;
        } else {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
        }
    }
}

string getStringInput(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

void vehicleEntry() {
    Vehicle v;
    v.vehicleNumber = getStringInput("\tEnter vehicle number (XXXX-XX-XXXX): ");
    char type = getIntegerInput("\tEnter vehicle type (Bicycle=1/Bike=2/Car=3): ");
    switch (type) {
        case 1:
            if (bicycles > 0) {
                v.vehicleType = "Bicycle";
                bicycles--;
            } else {
                cout << "No bicycle parking spaces left.\n";
                return;
            }
            break;
        case 2:
            if (bikes > 0) {
                v.vehicleType = "Bike";
                bikes--;
            } else {
                cout << "No bike parking spaces left.\n";
                return;
            }
            break;
        case 3:
            if (cars > 0) {
                v.vehicleType = "Car";
                cars--;
            } else {
                cout << "No car parking spaces left.\n";
                return;
            }
            break;
        default:
            cout << "Invalid vehicle type.\n";
            return;
    }
    v.vehicleName = getStringInput("\tEnter vehicle name: ");
    v.ownerName = getStringInput("\tEnter owner name: ");
    parkedVehicles.push_back(v);
    cout << "Vehicle entry recorded.\n";
}

void removeEntry() {
    string number = getStringInput("\tEnter vehicle number to remove (XXXX-XX-XXXX): ");
    for (auto it = parkedVehicles.begin(); it != parkedVehicles.end(); ++it) {
        if (it->vehicleNumber == number) {
            parkedVehicles.erase(it);
            cout << "Vehicle removed.\n";
            return;
        }
    }
    cout << "Vehicle number not found.\n";
}

void viewParkedVehicle() {
    cout << "Parked Vehicles:\n";
    for (const auto& v : parkedVehicles) {
        cout << v.vehicleNumber << " " << v.vehicleType << " " << v.vehicleName << " " << v.ownerName << "\n";
    }
}

void viewLeftParkingSpace() {
    cout << "Spaces left for Bicycle: " << bicycles << "\n";
    cout << "Spaces left for Bike: " << bikes << "\n";
    cout << "Spaces left for Car: " << cars << "\n";
}

int main() {
    while (true) {
        cout << "1. Vehicle Entry\n";
        cout << "2. Remove Entry\n";
        cout << "3. View Parked Vehicle\n";
        cout << "4. View Left Parking Space\n";
        cout << "5. Exit\n";
        int option = getIntegerInput("Select option: ");
        switch (option) {
            case 1:
                vehicleEntry();
                break;
            case 2:
                removeEntry();
                break;
            case 3:
                viewParkedVehicle();
                break;
            case 4:
                viewLeftParkingSpace();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid option.\n";
        }
    }
}
