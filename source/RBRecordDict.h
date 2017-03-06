#ifndef RBRECORDDICT
#define RBRECORDDICT
#include "RBtreeNode.h"

class RBRecordDict : public recordDict
{
protected:
    RBtreeNode *root; // root of tree
    ofstream outputFile; // for recursive calls to write to same file
// helper functions:
    RBtreeNode *successor(RBtreeNode *leaf);
    RBtreeNode *grandparent(RBtreeNode *n);
    RBtreeNode *uncle(RBtreeNode *n);
    RBtreeNode *sibling(RBtreeNode *n);
    RBtreeNode *search_help(string searchItem, RBtreeNode *leaf);
    RBcolor color(RBtreeNode *n);
    void destroy_tree(RBtreeNode *leaf);
    void rotate_left(RBtreeNode *x);
    void rotate_right(RBtreeNode *x);
    void insert_fixup(RBtreeNode *n);
    void insert_h(RBtreeNode *n, record *in);
    void remove_fixup(RBtreeNode *n);
    void inOrder_help(RBtreeNode *leaf);
    void inOrderTraversal();
    void preOrder_help(RBtreeNode *leaf);
    void preOrderTraversal();
    void postOrder_help(RBtreeNode *leaf);
    void postOrderTraversal();
// end of helper functions
public:
    void insert(record *in); // takes a pointer to record as input and inserts it
    RBtreeNode *search(string w); // takes string w as input and returns a pointer to RBtreeNode
    void remove(string w); // takes string w as input and returns nothing
    void toFile(string filename); // takes filename as input and returns nothing
    RBRecordDict(); // constructor that takes no input and sets root to NULL
    ~RBRecordDict(); // destructor that deletes all nodes in the tree
};

#endif // RBRECORDDICT
