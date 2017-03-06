#ifndef HTRECORDDICT
#define HTRECORDDICT
#include "RBRecordDict.h"
#include <cstdlib>

class HTrecordDict : public recordDict // derived from recordDict
{
protected:
    int size, a, b;
    cell **H; // cell pointer to pointer used for creation of hash table
    int hash(string str); // takes a string as input and returns an int
public:
    void insert(record *in); // takes a pointer to a record as input and returns nothing
    cell *search(string w); // takes a string as input and returns a pointer to cell
    void remove(string w); // takes a string as input and returns nothing
    void toFile(string filename); // takes string as input and returns nothing
    HTrecordDict(int num); // constructor that takes int as input
    ~HTrecordDict(); // destructor that deletes all aspects of hash table
};

#endif // HTRECORDDICT
