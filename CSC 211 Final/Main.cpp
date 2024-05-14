#include <iostream>
#include "Class1.h"
#include "Class2.h"
#include <iomanip>

using namespace std;


int main() {
    //Print Welcome Menu
    cout << setfill('-') << setw(120) << "-" << endl;
    cout << setfill(' ') << setw(80) << "WELCOME! THANK YOU FOR BANKING WITH CSC 211!" << endl;
    cout << setfill('-') << setw(120) << "-" << endl;
    cout << setfill(' ') << setw(75) << "Enter Customer Info To Get Started:" << endl;
    cout << setfill(' ') << setw(35) << " " << setfill('-') << setw(45) << "-" << endl;

    cout << setfill(' ') << setw(52) << "First Name: " << endl;
    cout << setfill(' ') << setw(51) << " " << setfill('-') << setw(15) << "-" << endl;
    cout << setfill(' ') << setw(51) << "Last Name: " << endl;
    cout << setfill(' ') << setw(50) << " " << setfill('-') << setw(15) << "-" << endl;
    cout << setfill(' ') << setw(56) << "Account Number: " << endl;
    cout << setfill(' ') << setw(55) << " " << setfill('-') << setw(15) << "-" << endl;
    cout << setfill(' ') << setw(56) << "Street Address: " << endl;
    cout << setfill(' ') << setw(55) << " " << setfill('-') << setw(15) << "-" << endl;
    cout << setfill(' ') << setw(46) << "City: " << endl;
    cout << setfill(' ') << setw(45) << " " << setfill('-') << setw(15) << "-" << endl;
    cout << setfill(' ') << setw(47) << "State: " << endl;
    cout << setfill(' ') << setw(46) << " " << setfill('-') << setw(15) << "-" << endl;
    cout << setfill(' ') << setw(50) << "Zip Code: " << endl;
    cout << setfill(' ') << setw(49) << " " << setfill('-') << setw(15) << "-" << endl;
    cout << setfill(' ') << setw(54) << "Phone Number: " << endl;
    cout << setfill(' ') << setw(53) << " " << setfill('-') << setw(15) << "-" << endl;


    //load customer data from file
    AllCustomerData allCustomers;
    allCustomers.loadFromFile("customer_info.txt");

    int choice;
    do {
        // Print the menu options
        cout << setfill('-') << setw(120) << "-" << endl;
        cout << setfill(' ') << setw(61) << "Menu:" << endl;
        cout << setfill(' ') << setw(35) << " " << setfill('-') << setw(45) << "-" << endl << endl;
        cout << setfill(' ') << setw(41) << "1. Print list of all customers" << setfill(' ') << setw(66) << "2. Sort and print customer list (Ascending)" << endl << endl;
        cout << setfill(' ') << setw(55) << "3. Sort and print customer list (Descending)" << setfill(' ') << setw(57) << "4. Print specific customer's account information" << endl << endl;
        cout << setfill(' ') << setw(53) << "5. Print total amount spent for a customer" << setfill(' ') << setw(32) << "6. Add a new customer" << endl << endl;
        cout << setfill(' ') << setw(36) << "7. Add multiple customers" << setfill(' ') << setw(60) << "8. Update customer's information" << endl << endl;
        cout << setfill(' ') << setw(43) << "9. Delete customer's information" << setw(54) << "10. Add a new customer's purchase" << endl << endl;
        cout << setfill(' ') << setw(50) << "11. Add multiple new customer purchases" << setw(50) << "12. Save customer info and purchases" << endl << endl;
        cout << setfill(' ') << setw(19) << "13. Exit" << endl << endl;
        cout << setfill(' ') << setw(30) << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; 
        }

        //switch statement to handle each menu choice
        switch (choice) {
        case 1:
            allCustomers.printAllCustomers();
            break;
        case 2:
            allCustomers.sortAndPrintCustomers(true);
            break;
        case 3:
            allCustomers.sortAndPrintCustomers(false);
            break;
        case 4: {
            int accountNumber;
            cout << "Enter account number: ";
            cin >> accountNumber;
            allCustomers.printCustomerInfo(accountNumber);
            break;
        }
        case 5: {
            int accountNumber;
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << setfill('-') << setw(45) << "-" << endl;
            cout << "Total spent: $" << allCustomers.calculateTotalSpend(accountNumber) << endl;
            break;
        }
        case 6: {
            Customer newCustomer;
            cout << "Enter customer information:" << endl;
            cout << "First Name: ";
            cin >> newCustomer.firstName;
            cout << "Last Name: ";
            cin >> newCustomer.lastName;
            cout << "Account #: ";
            cin >> newCustomer.accountNumber;
            cout << "Street Address: ";
            cin >> newCustomer.streetAddress;
            cout << "City: ";
            cin >> newCustomer.city;
            cout << "State: ";
            cin >> newCustomer.state;
            cout << "Zip Code: ";
            cin >> newCustomer.zipCode;
            cout << "Phone Number: ";
            cin >> newCustomer.phoneNumber;
            allCustomers.addNewCustomer(newCustomer);
            break;
        }
        case 7: {
            int numCustomers;
            cout << "Enter number of customers to add: ";
            cin >> numCustomers;
            vector<Customer> newCustomers(numCustomers);
            for (int i = 0; i < numCustomers; ++i) {
                cout << "Enter customer " << i + 1 << " information:" << endl;
                cout << "First Name: ";
                cin >> newCustomers[i].firstName;
                cout << "Last Name: ";
                cin >> newCustomers[i].lastName;
                cout << "Account #: ";
                cin >> newCustomers[i].accountNumber;
                cout << "Street Address: ";
                cin >> newCustomers[i].streetAddress;
                cout << "City: ";
                cin >> newCustomers[i].city;
                cout << "State: ";
                cin >> newCustomers[i].state;
                cout << "Zip Code: ";
                cin >> newCustomers[i].zipCode;
                cout << "Phone Number: ";
                cin >> newCustomers[i].phoneNumber;
            }
            allCustomers.addMultipleCustomers(newCustomers);
            break;
        }
        case 8: {
            int accountNumber;
            cout << "Enter account number to update: ";
            cin >> accountNumber;
            Customer updatedCustomer;
            cout << "Enter updated information:" << endl;
            cout << "First Name: ";
            cin >> updatedCustomer.firstName;
            cout << "Last Name: ";
            cin >> updatedCustomer.lastName;
            cout << "Street Address: ";
            cin >> updatedCustomer.streetAddress;
            cout << "City: ";
            cin >> updatedCustomer.city;
            cout << "State: ";
            cin >> updatedCustomer.state;
            cout << "Zip Code: ";
            cin >> updatedCustomer.zipCode;
            cout << "Phone Number: ";
            cin >> updatedCustomer.phoneNumber;
            allCustomers.updateCustomerInfo(accountNumber, updatedCustomer);
            break;
        }
        case 9: {
            int accountNumber;
            cout << "Enter account number to delete: ";
            cin >> accountNumber;
            allCustomers.deleteCustomerInfo(accountNumber);
            break;
        }
        case 10: {
            int accountNumber;
            cout << "Enter account number: ";
            cin >> accountNumber;
            Purchase newPurchase;
            cout << "Enter purchase information:" << endl;
            cout << "Item: ";
            cin >> newPurchase.item;
            cout << "Date: ";
            cin >> newPurchase.date;
            cout << "Amount: ";
            cin >> newPurchase.amount;
            allCustomers.addCustomerPurchase(accountNumber, newPurchase);
            break;
        }
        case 11: {
            int accountNumber;
            cout << "Enter account number: ";
            cin >> accountNumber;
            int numPurchases;
            cout << "Enter number of purchases to add: ";
            cin >> numPurchases;
            vector<Purchase> newPurchases(numPurchases);
            for (int i = 0; i < numPurchases; ++i) {
                cout << "Enter purchase " << i + 1 << " information:" << endl;
                cout << "Item: ";
                cin >> newPurchases[i].item;
                cout << "Date: ";
                cin >> newPurchases[i].date;
                cout << "Amount: ";
                cin >> newPurchases[i].amount;
            }
            allCustomers.addMultipleCustomerPurchases(accountNumber, newPurchases);
            break;
        }
        case 12: {
            string filename;
            cout << "Enter filename to save: ";
            cin >> filename;
            allCustomers.saveToFile(filename);
            break;
        }
        case 13: {
            cout << setfill('-') << setw(120) << "-" << endl;
            cout << setfill(' ') << setw(80) << "Thank you for using CSC 211 Bank. Goodbye!" << endl;
            cout << setfill('-') << setw(120) << "-" << endl;
            break;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;

        }

    //repeat menu until the user chooses to exit
    } while (choice !=13);

    return 0;
}
