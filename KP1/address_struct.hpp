#include <iostream>
#include <stdexcept>

using namespace std;

// оголошення структури «Адреса»: назва населеного пункту та назва вулиці – символьні рядки; номер будинку – ціле число.
struct Address{
    string cityName;
    string streetName;
    int homeNumber;
};

// виділення пам'яті під кожний елемент масиву
void createAddresses(Address* adr[], int n){
    for(int i=0; i<n; i++){
        adr[i] = new Address;
    }
}

// заповненням вмісту масиву з клавіатури
void addAddresses(Address *adr[], int n){
    for(int i=0; i<n; i++){
        cout << "Enter address as cityName streetName homeNumber" << endl;
        cin >> adr[i]->cityName >> adr[i]->streetName >> adr[i]->homeNumber;
    }
}

// підрахунок кількості елементів, що відповідають заданій вулиці
void countStreets(Address *adr[], int n, string streetToCount){
    int result = 0;
    for(int i=0; i<n; i++){
        if (adr[i]->streetName == streetToCount){
            result++;
        }
    }
    cout << endl << "Amount of streets with name " << streetToCount << " is: " << result << endl;
}

// додавання нового елемента після k-го ( k передати як параметр)
void insertAddress(Address *adr[], int n, int k){
    // якщо k більше за кількість елементів в масив
    if (k > n){
        throw std::invalid_argument( "Insert position should be less than array lenght" );
    }
    
    // рухаємося з кінця масиву до k - 1 елементу в масиві та пересуваємо елементи на 1 вперед. k - 1, бо користувач вводить місце починаючи з 1, індексація масиву з 0.
    for (int i = n - 1; i >= k - 1; i--){
        adr[i + 1] = adr[i];
    }
    
    // користувач вводить нову адреасу, яку він хоче вставити на k позицію
    cout << "Enter address as cityName streetName homeNumber" << endl;
    adr[k-1] = new Address;
    cin >> adr[k-1]->cityName >> adr[k-1]->streetName >> adr[k-1]->homeNumber;
}

// поміняти місцями k-й і j-й елементи (k і j передати як параметр)
void switchAddresses(Address *adr[], int n, int from, int to){
    // валідація індексів, які користувач хоче поміняти
    if (from - 1 < 0 && to - 1 < from - 1 & from - 1 > n & to - 1 > n){
        throw std::invalid_argument( "Received invalid values.'from' param should be equal or greater than 0.\
                                    'from' param should be less than size of array. \
                                    'from' param should be greater than 'to' param." );
    }
    // переміщення елементів
    Address *temp = adr[from - 1];
    adr[from - 1] = adr[to - 1];
    adr[to - 1] = temp;
}

// виведення вмісту створеного масиву на екран
void printAddresses(Address *adr[], int n){
    for(int i=0; i<n; i++){
        cout << "Address is: ";
        cout << adr[i]->cityName << " " << adr[i]->streetName << " " << adr[i]->homeNumber << endl;
    }
}

// створення текстового файлу, кожний рядок якого міститиме інформацію про одну адресу, всього до файлу записується n адрес, n вводиться з клавіатури
void writeToFIle(Address *adr[], int n){
    //створення нового потоку
    FILE *fp;
    
    // введення ім'я файлу з клавіатури
    string fname;
    cout << "Enter path to file: " << endl;
    cin >> fname;
    
    if ((fp=fopen(fname.c_str(), "w")) == NULL){
        printf("Can not open file %s.\n", fname.c_str());
        exit(1);
    }
    
    // запис до файлу ввдених адрес
    for(int i=0; i<n; i++){
        fprintf(fp, "%s, %s, %d\n", adr[i]->cityName.c_str(), adr[i]->streetName.c_str(), adr[i]->homeNumber);
    }
    
    // закриття файлу
    fclose(fp);
}

void deleteAddress(Address *adr[], int n){
    for(int i = 0; i < n; i++){
        delete adr[i];
    }
}
