#ifndef CELL
#define CELL
#include "container.h"

class cell : public container // derived from container
{
protected:
    cell *previous;
    cell *next;
public:
    // friend classes allow access to protected members:
    friend class listRecordDict;
    friend class HTrecordDict;
    // constructors taking various pointers as inputs:
    cell(record *d);
    cell(record *d, cell *p);
    cell(record *d, cell *p, cell *r);
};

#endif // CELL
