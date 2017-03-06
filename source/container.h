#ifndef CONTAINER
#define CONTAINER
#include "record.h"

/*
 * container is a general container used for the record of an item
 * so that all three data structures (red-black tree, linked-list, and hash table)
 * can use this general "dictionary" data structure.
 */

class container
{
public:
    record *data; // pointer to record data
};

#endif // CONTAINER
