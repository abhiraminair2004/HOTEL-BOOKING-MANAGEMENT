# HOTEL-BOOKING-MANAGEMENT
Clazire Hotel Booking System
Welcome to the Clazire Hotel Booking System! This application allows users to book hotel rooms, select add-on services, and view their billing details in a simple and user-friendly manner.

Features
Room Booking: Choose between Normal and Luxury rooms.
Add-On Services: Optionally add laundry service and pool access (for Normal rooms).
Discounts: Automatic discounts based on the number of members and length of stay.
Billing Summary: Detailed billing summary including room charges, buffet charges, add-on costs, discounts, and taxes.
Complimentary Services: Free WiFi, gym access, and breakfast for all guests.
Requirements
A C++ compiler (e.g., g++, clang++)
Standard C++ library
How to Run
Clone the Repository (if applicable):

bash
Copy code
git clone https://github.com/yourusername/clazire-hotel.git
cd clazire-hotel
Compile the Code: Use a C++ compiler to compile the code. For example, using g++:

bash
Copy code
g++ -o hotel_booking hotel_booking.cpp
Run the Application: Execute the compiled program:

bash
Copy code
./hotel_booking

Usage
Start the Program: Run the application as described above.
View Offers: The application will display offers available for Normal and Luxury rooms.
Input Guest Details: Enter your full name, number of days for stay, and number of members in your party.
Select Room Type: Choose between Normal and Luxury rooms.
Select Add-On Services: Optionally select laundry service and pool access (only for Normal rooms).
View Bill: After completing the selection, the program will display a detailed bill.
Make Additional Bookings: You can choose to make another booking or exit the program.
Code Structure
Room: Base class for managing room bookings and charges.
NormalRoom: Derived class for handling normal room bookings and discounts.
LuxuryRoom: Derived class for managing luxury room bookings and discounts.
main: The entry point of the program, handling user interaction and flow of the application.
