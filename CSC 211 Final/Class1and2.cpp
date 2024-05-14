#include "Class1.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

//load customer data from a file
void AllCustomerData::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << endl;
        return;
    }

    Customer customer;
    while (file >> customer.firstName >> customer.lastName >> customer.accountNumber >> customer.streetAddress
        >> customer.city >> customer.state >> customer.zipCode >> customer.phoneNumber) {
        customers.push_back(customer);
    }

    file.close();

}


//print information of all customers
void AllCustomerData::printAllCustomers() const {
    cout << setfill('-') << setw(120) << "-" << endl;
    cout  << "List of all customers:" << endl;
    cout << setfill('-') << setw(45) << "-" << endl;
    for (const auto& customer : customers) {
        cout << "Name: " << customer.firstName << " " << customer.lastName << endl;
        cout << "Account #: " << customer.accountNumber << endl;
        cout << "Address: " << customer.streetAddress << ", " << customer.city << ", " << customer.state << ", " << customer.zipCode << endl;
        cout << "Phone Number: " << customer.phoneNumber << endl;
        cout << endl;
    }
}

//sort and print customers by last name
void AllCustomerData::sortAndPrintCustomers(bool ascending) const {
    vector<Customer> sortedCustomers = customers;
    if (ascending) {
        sort(sortedCustomers.begin(), sortedCustomers.end(), [](const Customer& a, const Customer& b) {
            return a.lastName < b.lastName; // Sort by last name in ascending order
            });
    }
    else {
        sort(sortedCustomers.begin(), sortedCustomers.end(), [](const Customer& a, const Customer& b) {
            return a.lastName > b.lastName; // Sort by last name in descending order
            });
    }

    cout << setfill('-') << setw(120) << "-" << endl;
    cout << "Sorted list of customers:" << endl;
    cout << setfill('-') << setw(45) << "-" << endl;
    for (const auto& customer : sortedCustomers) {
        cout << "Name: " << customer.firstName << " " << customer.lastName << endl;
        cout << "Account #: " << customer.accountNumber << endl;
        cout << "Address: " << customer.streetAddress << ", " << customer.city << ", " << customer.state << ", " << customer.zipCode << endl;
        cout << "Phone Number: " << customer.phoneNumber << endl;
        cout << endl;
    }
}

//print information of a specific customer by account number
void AllCustomerData::printCustomerInfo(int accountNumber) const {
    auto it = find_if(customers.begin(), customers.end(), [accountNumber](const Customer& c) {
        return c.accountNumber == accountNumber;
        });

    if (it != customers.end()) {
        cout << setfill('-') << setw(120) << "-" << endl;
        cout << "Customer Information:" << endl;
        cout << setfill('-') << setw(45) << "-" << endl;
        cout << "Name: " << it->firstName << " " << it->lastName << endl;
        cout << "Account #: " << it->accountNumber << endl;
        cout << "Address: " << it->streetAddress << ", " << it->city << ", " << it->state << ", " << it->zipCode << endl;
        cout << "Phone Number: " << it->phoneNumber << endl;
        cout << "\n";
    }
    else {
        cout << "Customer with account number " << accountNumber << " not found." << endl;
    }
}
//calculate the total spent of a customer by account number
double AllCustomerData::calculateTotalSpend(int accountNumber) const {
    double totalSpend = 0.0;
    for (const auto& purchase : purchases) {
        if (purchase.accountNumber == accountNumber) { // Filter purchases by account number
            totalSpend += purchase.amount;
        }
    }
    return totalSpend;
}

//add a new customer
void AllCustomerData::addNewCustomer(const Customer& customer) {
    customers.push_back(customer);
}

//add multiple customers
void AllCustomerData::addMultipleCustomers(const vector<Customer>& newCustomers) {
    for (const auto& customer : newCustomers) {
        addNewCustomer(customer);
    }
}

//update information of a customer by account number
void AllCustomerData::updateCustomerInfo(int accountNumber, const Customer& updatedInfo) {
    auto it = find_if(customers.begin(), customers.end(), [accountNumber](const Customer& c) {
        return c.accountNumber == accountNumber;
        });

    if (it != customers.end()) {
        *it = updatedInfo; // Update customer information
    }
    else {
        cout << "Customer with account number " << accountNumber << " not found." << endl;
    }
}

//delete information of a customer by account number
void AllCustomerData::deleteCustomerInfo(int accountNumber) {
    auto it = find_if(customers.begin(), customers.end(), [accountNumber](const Customer& c) {
        return c.accountNumber == accountNumber;
        });

    if (it != customers.end()) {
        customers.erase(it); // Delete customer information
    }
    else {
        cout << "Customer with account number " << accountNumber << " not found.\n";
    }
}

//add a purchase for a specific customer
void AllCustomerData::addCustomerPurchase(int accountNumber, const Purchase& purchase) {
    Purchase newPurchase = purchase; 
    newPurchase.accountNumber = accountNumber; 
    purchases.push_back(newPurchase);
}


//add multiple purchases for a specific customer
void AllCustomerData::addMultipleCustomerPurchases(int accountNumber, const vector<Purchase>& newPurchases) {
    for (const auto& purchase : newPurchases) {
        addCustomerPurchase(accountNumber, purchase);
    }
}

//save customer data to a file
void AllCustomerData::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << endl;
        return;
    }

    for (const auto& customer : customers) {
        // Initialize total amount spent for this customer
        double totalAmountSpent = 0.0;

        // Calculate total amount spent by this customer
        for (const auto& purchase : purchases) {
            if (purchase.accountNumber == customer.accountNumber) {
                totalAmountSpent += purchase.amount;
            }
        }

        // Save customer information and total amount spent
        file << customer.firstName << " " << customer.lastName << " " << customer.accountNumber << " "
            << customer.streetAddress << " " << customer.city << " " << customer.state << " "
            << customer.zipCode << " " << customer.phoneNumber << " "
            << "Total Amount Spent: " << totalAmountSpent << endl;
    }

    file.close();
}

