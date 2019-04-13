void testCountStreetsNameAndPrintResults(Address* adr[], int n, string streetName){
    cout << "_________________________________________" << endl;
    cout << endl << "Test started" << endl;
    printAddresses(adr, n); // вивід масиву адрес
    countStreets(adr, n, streetName);
    cout << "Test ended" << endl;
    cout << "_________________________________________" << endl;
}

void testSwitchAddresses(Address* adr[], int n, int from, int to){
    cout << "_________________________________________" << endl;
    cout << endl << "Test started" << endl;
    cout << "Array before switch addresses from " << from << " to " << to << endl;
    printAddresses(adr, n); // вивід масиву адрес
    switchAddresses(adr, n, from, to);
    cout << "Array after switch: " << endl;
    printAddresses(adr, n); // вивід масиву адрес
    cout << "Test ended" << endl;
    cout << "_________________________________________" << endl;
}

void testInsertAddress(Address* adr[], int n, int k){
    cout << "_________________________________________" << endl;
    cout << endl << "Test started" << endl;
    cout << "Array before insertion address to position " << k << endl;
    printAddresses(adr, n); // вивід масиву адрес
    insertAddress(adr, n, k);
    cout << "Array after insertion: " << endl;
    printAddresses(adr, n + 1); // вивід масиву адрес
    cout << "Test ended" << endl;
    cout << "_________________________________________" << endl;
}
