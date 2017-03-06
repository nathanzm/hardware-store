#ifndef LISTRECORDDICT
#define LISTRECORDDICT
#include "recordDict.h"

class listRecordDict : public recordDict // derived from recordDict
{
protected:
    cell *first;
    cell *last;
public:
    listRecordDict(); // constructor that sets first and last to NULL
    ~listRecordDict(); // destructor that that deletes all cells in the linked list
    void insert(record *in); // takes pointer to record in and inserts it at end of list
    cell *search(string w); // searches for input and returns pointer to cell
    void remove(string w); // removes the searched input from the list
    void toFile(string filename); // writes the content of all the cells to a file
};

#endif // LISTRECORDDICT
