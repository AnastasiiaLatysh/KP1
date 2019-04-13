//
//  main.cpp
//  labs_kpi
//
//  Created by Anastasiia Latysh on 4/13/19.
//  Copyright © 2019 Anastasiia Latysh. All rights reserved.
//

#include <iostream>
#include "address_struct.hpp"
#include "tests.hpp"

int main(int argc, const char * argv[]) {
    int n;
    cout << "How many addresses?" << endl;
    cin >> n;
    Address *addresses[n];
    createAddresses(addresses, n); // створення масиву у динамічній RAM
    addAddresses(addresses, n); // доддавання об'єктів до масиву адрес
    
    testCountStreetsNameAndPrintResults(addresses, n, "StreetExist");
    testCountStreetsNameAndPrintResults(addresses, n, "StreetNotExist");
    
    testSwitchAddresses(addresses, n, 1, 2);
    testSwitchAddresses(addresses, n, 5, 1);
    
    testInsertAddress(addresses, n, 1);
    testInsertAddress(addresses, n + 1, 5);
    
    writeToFIle(addresses, n + 1);
    
    deleteAddress(addresses, n + 1);
    
    return 0;
}
