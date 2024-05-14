#pragma once


#ifndef CUSTOMER_AND_PURCHASE_H
#define CUSTOMER_AND_PURCHASE_H

#include <string>
#include <vector>

using namespace std;

//class that has AllPurchase Data Model
class Purchase {
public:
    int accountNumber;
    string item;
    string date;
    double amount;

    // Constructor
    Purchase() = default;
    Purchase(int accNum, const string& itm, const string& dt, double amt)
        : accountNumber(accNum), item(itm), date(dt), amount(amt) {}
};

//class that has AllCustomer Data Model
class Customer {
public:
    string firstName;
    string lastName;
    int accountNumber;
    string streetAddress;
    string city;
    string state;
    string zipCode;
    string phoneNumber;
    // Vector to store customer purchases
    vector<Purchase> purchases;

    // Constructor
    Customer() = default;
    Customer(const string& fName, const string& lName, int accNum, const string& address,
        const string& cty, const string& st, const string& zip, const string& phone)
        : firstName(fName), lastName(lName), accountNumber(accNum), streetAddress(address),
        city(cty), state(st), zipCode(zip), phoneNumber(phone) {}
};

#endif 