#include "Class1.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

//load purchase data from a file
vector<Purchase> Purchase::loadFromFile(const string & filename) {
    vector<Purchase> purchases;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << endl;
        return purchases;
    }

    Purchase purchase;
    while (file >> purchase.accountNumber >> purchase.item >> purchase.date >> purchase.amount) {
        purchases.push_back(purchase);
    }

    file.close();
    return purchases;
}


void AllCustomerData::loadPurchaseDataFromFile(const string& filename) {
    purchases = Purchase::loadFromFile(filename);

    //Match purchases with customer based on account number
    for (auto& customer : customers) {
        customer.purchases.clear();
        for (const auto& purchase : purchases) {
            if (purchase.accountNumber == customer.accountNumber) {
                customer.purchases.push_back(purchase);
            }
        }
    }
}
