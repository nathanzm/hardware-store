#ifndef RBTREENODE
#define RBTREENODE
#include "inventory.h"

enum RBcolor{Red, Black}; // enumeration type for RBcolor

class RBtreeNode : public container // derived from container
{
protected:
    record *data;
    RBtreeNode *parent, *left, *right;
    RBcolor color;
public:
    friend class RBRecordDict; // gives RBRecordDict access to protected members
    RBtreeNode(record *d); // constructor that takes a pointer to record d as input
    RBtreeNode(record *d, RBtreeNode *p); // constructor that takes record d and RBtreeNode p as input
};

#endif // RBTREENODE
