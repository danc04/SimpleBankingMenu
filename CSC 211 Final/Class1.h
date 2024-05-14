#pragma once

#ifndef ALLCUSTOMERS_H
#define ALLCUSTOMERS_H

#include <vector>
#include <string>
#include "Class2.h"

using namespace std;

class AllCustomerData {
public:
    //load customer data from a file
    void loadFromFile(const string& filename);

    void loadPurchaseDataFromFile(const string& filename);

    //print information of all customers
    void printAllCustomers() const;

    //sort and print customers by last name
    void sortAndPrintCustomers(bool ascending) const;

    //print information of a specific customer by account number
    void printCustomerInfo(int accountNumber) const;

    //calculate the total spent of a customer by account number
    double calculateTotalSpend(int accountNumber) const;

    //add a new customer
    void addNewCustomer(const Customer& customer);

    //add multiple customers
    void addMultipleCustomers(const vector<Customer>& newCustomers);

    //update information of a customer by account number
    void updateCustomerInfo(int accountNumber, const Customer& updatedInfo);

    //delete information of a customer by account number
    void deleteCustomerInfo(int accountNumber);

    //add a purchase for a specific customer
    void addCustomerPurchase(int accountNumber, const Purchase& purchase);

    //add multiple purchases for a specific customer
    void addMultipleCustomerPurchases(int accountNumber, const vector<Purchase>& newPurchases);

    //save customer data to a file
    void saveToFile(const string& filename) const;

private:
    // Vector to store customer objects
    vector<Customer> customers; 

    // Vector to store purchase objects
    vector<Purchase> purchases; 
};

#endif
