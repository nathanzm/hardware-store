#ifndef INVENTORY
#define INVENTORY
#include "listRecordDict.h"

class inventory
{
protected:
    recordDict* dict;
public:
    inventory(recordDict* pointer); // constructor takes pointer to recordDict
    ~inventory(); // destructor that calls destructor of recordDict
    void search(string str); // takes a string and returns nothing
    void sell(string str, int num); // takes a string and integer and returns nothing
    void add(record* item); // takes a string and returns nothing
    void remove(string str); // takes a string and returns nothing
    void readFile(string filename); // takes a string and returns nothing
    void toFile(string filename); // takes a string and returns nothing
};

#endif // INVENTORY
