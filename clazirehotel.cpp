#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Room {
protected:
    string guestName;
    int days, members;
    float roomCharge;
    float buffetCharge;
    float taxPercentage;
    bool addLaundry, addPoolAccess; 
    int laundryDays, poolAccessDays;

public:
    Room(string name, int days, int members) : guestName(name), days(days), members(members) {
        buffetCharge = 700.0 * days * members; // Buffet cost per person per day
        taxPercentage = 0.18; // 18% Tax
        addLaundry = false;
        addPoolAccess = false; 
        laundryDays = 0;
        poolAccessDays = 0;
    }

    virtual float calculateDiscount() {
        return 0.0;
    }

    // Add-on services with validation
    void selectAddOnServices(bool isLuxury) {
        char choice;

        // Complimentary WiFi, Gym, and Breakfast (Free services)
        cout << "\n~ Complimentary services:\n";
        cout << "* Free WiFi for all guests\n";
        cout << "* Free Gym access for all guests\n";
        cout << "* Free Breakfast for all guests\n";

        // Laundry Service (For both Normal and Luxury rooms)
        cout << "\nWould you like to add Laundry service (Rs. 300/day)? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            addLaundry = true;
            do {
                cout << "For how many days would you like Laundry service?: ";
                cin >> laundryDays;
                if (laundryDays < 0) {
                    cout << "Error: Laundry service days cannot be negative. Please enter a valid number.\n";
                } else if (laundryDays > days) {
                    cout << "Error: You cannot request laundry service for more than " << days << " days of stay.\n";
                }
            } while (laundryDays < 0 || laundryDays > days);
        }

        if (!isLuxury) {
            // Pool Access (Only prompt for normal rooms)
            cout << "Would you like to add Pool Access (Rs. 400/day)? (y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                addPoolAccess = true;
                do {
                    cout << "For how many days would you like Pool Access?: ";
                    cin >> poolAccessDays;
                    if (poolAccessDays < 0) {
                        cout << "Error: Pool access days cannot be negative. Please enter a valid number.\n";
                    } else if (poolAccessDays > days) {
                        cout << "Error: You cannot request pool access for more than " << days << " days of stay.\n";
                    }
                } while (poolAccessDays < 0 || poolAccessDays > days);
            }
        } else {
            // Complimentary pool access for luxury rooms
            cout << "- Complimentary Pool Access for all guests (Luxury Room)\n";
        }
    }

    float calculateAddOnCost() {
        float addOnCost = 0;
        if (addLaundry) addOnCost += 300.0 * laundryDays;
        if (addPoolAccess) addOnCost += 400.0 * poolAccessDays;
        return addOnCost;
    }

    float calculateTotal() {
        float discount = calculateDiscount();
        float tax = taxPercentage * roomCharge;
        float addOnCost = calculateAddOnCost();
        float totalAmount = (roomCharge + buffetCharge + addOnCost - discount) + tax;
        return totalAmount;
    }

    void displayBill() {
        float discount = calculateDiscount();
        float tax = taxPercentage * roomCharge;
        float addOnCost = calculateAddOnCost();
        float totalAmount = calculateTotal();

        cout << "\n~~~~~~~~~~~~~~~~~~~~~*~\n";
        cout << "\t\t Clazire Hotel\n";
        cout << "*********************\n";
        cout << "Guest Name        : " << guestName << endl;
        cout << "Room Type         : " << getRoomType() << endl;
        cout << "No. of Days       : " << days << endl;
        cout << "No. of Members    : " << members << endl;
        cout << "*********************\n";
        cout << "Itemized Charges: \n";
        cout << "Room Charges      : Rs." << fixed << setprecision(2) << roomCharge << endl;
        cout << "Buffet Charges    : Rs." << fixed << setprecision(2) << buffetCharge << endl;
        cout << "Add-On Services   : Rs." << fixed << setprecision(2) << addOnCost << endl;
        cout << "Discount Applied  : Rs." << fixed << setprecision(2) << discount << endl;
        cout << "Tax               : Rs." << fixed << setprecision(2) << tax << endl;
        cout << "*********************\n";
        cout << "Total Amount      : Rs." << fixed << setprecision(2) << totalAmount << endl;
        cout << "*********************\n";
        cout << "Complimentary Services: WiFi, Gym Access, Breakfast\n";
    }

    virtual string getRoomType() = 0;

    virtual void showOffers() {
        cout << "Currently no offers available for this room type.\n";
    }
};

// Derived class for Normal Room
class NormalRoom : public Room {
public:
    NormalRoom(string name, int days, int members) : Room(name, days, members) {
        roomCharge = 3000.0 * days; // Room charge is Rs. 3000 per day
    }

    float calculateDiscount() {
        if (members > 3) {
            return roomCharge * 0.1;
        }
        return 0.0;
    }

    string getRoomType() {
        return "Normal Room";
    }

    void showOffers() {
        cout << "Special Offers for Normal Rooms: \n";
        if (members > 3) {
            cout << "* Get 10% off on room charges for more than 3 members!\n";
        } else {
            cout << "* Stay 3 days and get a free buffet for 1 day!\n";
        }
    }
};

// Derived class for Luxury Room
class LuxuryRoom : public Room {
public:
    LuxuryRoom(string name, int days, int members) : Room(name, days, members) {
        roomCharge = 6000.0 * days; // Room charge is Rs. 6000 per day
    }

    float calculateDiscount() {
        if (days > 5) {
            return roomCharge * 0.15;
        }
        return 0.0;
    }

    string getRoomType() {
        return "Luxury Room";
    }

    void showOffers() {
        cout << "Exclusive Offers for Luxury Rooms: \n";
        if (days > 5) {
            cout << "* Get 15% off for stays longer than 5 days!\n";
        } else {
            cout << "* Complimentary pool access for each guest!\n";
        }
    }
};

// Function to show all offers before the user selects a room type
void showAllOffers() {
    NormalRoom normalRoom("Guest", 1, 1);
    LuxuryRoom luxuryRoom("Guest", 1, 1);

    cout << "\n~~~~~~~~~~~~~~~~~~~~~*~\n";
    cout << "Offers for Room Types:\n";
    cout << "*********************\n";
    
    cout << "\nNormal Room Offers:\n";
    normalRoom.showOffers();
    
    cout << "\nLuxury Room Offers:\n";
    luxuryRoom.showOffers();
    
    cout << "*********************\n"; // Added missing closing line
}

int main() {
    string guestName;
    int roomChoice, days, members, moreBookings;

    cout << "~~~~~~~~~~~~~~~~~\n";
    cout << "\tWelcome to Clazire Hotel\n";
    cout << "~~~~~~~~~~~~~~~~~\n";
    cout << "Experience luxury and comfort like never before!\n";
    cout << "~~~~~~~~~~~~~~~~~\n";

    do {
        // Display all offers before the user selects a room
        showAllOffers();

        // Input guest details
        cout << "\nPlease provide your details to proceed with the booking:\n";
        cout << "Enter your full name: ";
        //cin.ignore(); // Clear the input buffer before getline
        getline(cin, guestName);
        if (guestName.empty()) {
            cout << "Error: Guest name cannot be empty. Please try again.\n";
            continue; // Skip to the next iteration of the loop
        }

        // Input days with validation
        do {
            cout << "Enter the number of days you want to stay: ";
            cin >> days;
            if (days <= 0) {
                cout << "Error: Number of days must be positive. Please try again.\n";
            }
        } while (days <= 0);

        // Input members with validation
        do {
            cout << "Enter the number of members: ";
            cin >> members;
            if (members <= 0) {
                cout << "Error: Number of members must be positive. Please try again.\n";
            }
        } while (members <= 0);

        // Choose room type with validation
        do {
            cout << "\nChoose Room Type:\n";
            cout << "1. Normal Room\n";
            cout << "2. Luxury Room\n";
            cout << "Enter your choice (1 or 2): ";
            cin >> roomChoice;

            if (roomChoice == 1) {
                NormalRoom normalRoom(guestName, days, members);
                normalRoom.selectAddOnServices(false);
                normalRoom.displayBill();
                break; // Exit loop after successful booking
            } else if (roomChoice == 2) {
                LuxuryRoom luxuryRoom(guestName, days, members);
                luxuryRoom.selectAddOnServices(true);
                luxuryRoom.displayBill();
                break; // Exit loop after successful booking
            } else {
                cout << "Error: Invalid room choice. Please select either 1 or 2.\n";
            }
        } while (true);

        // Ask if the user wants to make another booking
        cout << "\nDo you want to make another booking? (1 for Yes, 0 for No): ";
        cin >> moreBookings;

    } while (moreBookings == 1);

    cout << "\nThank you for choosing Clazire Hotel. Have a wonderful day!\n";
    cout << "We look forward to welcoming you again soon!\n";
    cout << "~~~~~~~~~~~~~~~~~\n";
    return 0;
}
