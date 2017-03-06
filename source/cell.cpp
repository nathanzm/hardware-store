#include "cell.h"
/*
 * constructor that takes a pointer to record d as input and initializes
 * data to d and sets all pointers to NULL
 */
cell :: cell(record *d)
{
    data = d;
    previous = NULL;
    next = NULL;
}

/*
 * constructor that takes a pointer to record d as input and a pointer
 * to cell p as input and then initializes data to d, previous to p,
 * and next to NULL.
 */
cell :: cell(record *d, cell *p)
{
    data = d;
    previous = p;
    next = NULL;
}

/*
 * constructor that takes a pointer to record d as input and a pointer
 * to cell p and r as input then sets data, previous, and next in respectively.
 */
cell :: cell(record *d, cell *p, cell *r)
{
    data = d;
    previous =  p;
    next = r;
}
