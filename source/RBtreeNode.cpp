#include "RBtreeNode.h"

// constructor that initializes data to d and all other pointers to NULL
RBtreeNode :: RBtreeNode(record *d)
{
    data = d;
    parent = NULL;
    left = NULL;
    right = NULL;
    color = Red; // set color to Red
}

// constructor that initializes data to d, parent to p, and all other pointers to NULL
RBtreeNode :: RBtreeNode(record *d, RBtreeNode *p)
{
    data = d;
    parent = p;
    left = NULL;
    right = NULL;
    color = Red; // set color to Red
}
