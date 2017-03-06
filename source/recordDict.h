#ifndef RECORDDICT
#define RECORDDICT
#include "record.h"
#include "cell.h"

// class recordDict contains only pure virtual functions
class recordDict
{
public:
    virtual void insert(record *in) = 0;
    virtual container *search(string w) = 0;
    virtual void remove(string w) = 0;
    virtual void toFile(string w) = 0;
    virtual ~recordDict(){}; // virtual destructor that does nothing
};

#endif // RECORDDICT
