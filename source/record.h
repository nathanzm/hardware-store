#ifndef RECORD
#define RECORD
// includes apply for entire project in this case
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std; // will apply for all files in project

class record
{
protected:
    string barcode;
    string name;
    float price;
    int quantity;
public:
    record(string c, string n, float p, int q); // will initialize barcode, name, price, quantity respectively
    string toString(); // returns string that contains all elements of record
    string fileString(); // returns string that contains barcode, name, price, quantity
    string getBarcode(); // return string that contains barcode
    float sell(int integer); // decreases quantity by integer if quantity minus input is greater than 0
    // overloaded operators:
    bool operator ==(record instance);
    bool operator ==(string str);
    bool operator <(record instance);
    bool operator <(string str);
    bool operator >(record instance);
    bool operator >(string str);
};

#endif // RECORD
