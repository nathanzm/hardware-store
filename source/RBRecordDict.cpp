#include "RBRecordDict.h"

// successor function same as in binary search tree
RBtreeNode* RBRecordDict :: successor(RBtreeNode *leaf)
{
    RBtreeNode *z = leaf -> right;
    while (z -> left != NULL)
    {
        z = z -> left;
    }
    return z;
}

// function used for creating instance of grandparent based on input n
RBtreeNode* RBRecordDict :: grandparent(RBtreeNode *n)
{
    if (n != NULL && n -> parent != NULL) // if n is not null and n's parent is not null
    {
        return n -> parent -> parent; // return n's parent's parent
    }
    else
    {
        return NULL;
    }
}

// function used for creating instance of uncle based on input n
RBtreeNode* RBRecordDict :: uncle(RBtreeNode *n)
{
    RBtreeNode *g = grandparent(n);

    if (g == NULL)
    {
        return NULL;
    }
    else if (g -> left == n -> parent) // if grandparent of n's left is n's parent
    {
        return g -> right; // return grandparent's right
    }
    else
    {
        return g -> left; // return grandparent's left
    }
}

// function used for creating instance of sibling based on input n
RBtreeNode* RBRecordDict :: sibling(RBtreeNode *n)
{
    if (n -> parent == NULL) // if n's parent is NULL
    {
        return NULL;
    }
    else if (n -> parent -> left == n) // if n's parent's left is n
    {
        return n -> parent -> right; // return n's parent's right
    }
    else
    {
        return n -> parent -> left; // return n's parent's left
    }
}

/*
 * function used for searching the red-black tree. it takes a string and RBtreeNode pointer
 * as input and searches the tree for that string.
 */
RBtreeNode* RBRecordDict :: search_help(string searchItem, RBtreeNode *leaf)
{
    if (leaf == NULL)
    {
        return NULL; // return false
    }
    else if (leaf -> data -> operator==(searchItem)) // overloaded operator
    {
        return leaf; // return true
    }
    else if (leaf -> data -> operator>(searchItem)) // overloaded operator
    {
        return search_help(searchItem, leaf -> left); // recursive call
    }
    else
    {
        return search_help(searchItem, leaf -> right); // recursive call
    }
}

// color function is used to check the color of given input
RBcolor RBRecordDict :: color(RBtreeNode *n)
{
    if (n == NULL) // checks if null
    {
        return Black; // n is black
    }
    else
    {
        return n -> color; // otherwise return the color of n
    }
}

// this function is used in the deconstructor to delete all nodes in the tree
void RBRecordDict :: destroy_tree(RBtreeNode *leaf)
{
    if (leaf != NULL)
    {
        destroy_tree(leaf -> left);
        destroy_tree(leaf -> right);
        delete leaf;
    }
}

// performs a left rotation on a given node
void RBRecordDict :: rotate_left(RBtreeNode *x)
{
    RBtreeNode *y; // declare y pointer of RBtreeNode type
    y = x -> right; // set y to x's right
    x -> right = y -> left; // set x's right to y's left

    if (y -> left != NULL) // if y's left is not NULL
    {
        y -> left -> parent = x; // set y's left's parent to x
    }

    y -> parent = x -> parent; // set y's parent to x's parent

    if (x -> parent == NULL) // if x's parent is NULL
    {
        root = y; // set root to y
    }
    else
    {
        if (x == x -> parent -> right) // else if x is x's parent's right
        {
            x -> parent -> right = y; // set x's parent's right to y
        }
        else
        {
            x -> parent -> left = y; // set x's parent's left to y
        }
    }

    y -> left = x; // set y's left to x
    x -> parent = y; // set x's parent to y
}

// performs a right rotation on a given node
void RBRecordDict :: rotate_right(RBtreeNode *x)
{
    RBtreeNode *y; // declare y pointer of RBtreeNOde type
    y = x -> left; // set y to x's left
    x -> left = y -> right; // set x's left to y's right

    if (y -> right != NULL) // if y's right is not NULL
    {
        y -> right -> parent = x; // set y's right's parent to x
    }

    y -> parent = x -> parent; // set y's parent to x's parent

    if (x -> parent == NULL) // if x's parent is NULL
    {
        root = y; // set root to y
    }
    else
    {
        if (x == x -> parent -> left) // else if x is x's parent's left
        {
            x -> parent -> left = y; // set x's parent's left to y
        }
        else
        {
            x -> parent -> right = y; // set x's parent's right to y
        }
    }

    y -> right = x; // set y's right to x
    x -> parent = y; // set x's parent to y
}

/*
 * ASSUMPTIONS: n is red and the only properties of RB tree that might be violated are:
 * maybe n is the root or maybe n has a red parent.
 */
void RBRecordDict :: insert_fixup(RBtreeNode *n)
{
    if (n == root) // CASE 1: if n is the root
    {
        n -> color = Black; // color n black
        return;
    }
    if (n -> parent -> color == Black) // CASE 2: if n's parent is black
    {
        return; // nothing to do
    }

    /*
     * by now, we know n's parent is red, so n's parent can't be the root.
     * so n has a grandparent who is black.
     */
     RBtreeNode *p = n -> parent;
     RBtreeNode *g = grandparent(n);
     RBtreeNode *u = uncle(n);

    if (color(u) == Black) // CASE 3: u is black; careful u could be NULL!
    {
        if (g -> left == p && p -> right == n) // if g's left is p and p's right is n
        {
            rotate_left(p); // perform a left rotation on p
            swap(p,n); // swap p and n
        }
        else if (g -> right == p && p -> left == n) // if g's right is p and p's left is n
        {
            rotate_right(p); // perform a right rotation on p
            swap(p,n); // swap p and n
        }

        p -> color = Black;
        g -> color = Red;

        if (p -> left == n) // if p's left is n
        {
            rotate_right(g); // perform a right rotation on g
        }
        else
        {
            rotate_left(g); // perform a left rotation on g
        }
        return;
    }

    if (u -> color == Red) // CASE 4: if u is red
    {
        p -> color = Black; // color p black
        u -> color = Black; // color u black
        g -> color = Red; // color g red
        insert_fixup(g); // recursive call to insert_fixup on g
    }
}

// helper function for inserting
void RBRecordDict :: insert_h(RBtreeNode *n, record *in)
{
    if (n -> data -> operator>(*in)) // if data in n is less than record
    {
        if (n -> left == NULL) // if n's left is NULL
        {
            // new RBtreeNode using constructor that takes record pointer and RBtreeNode pointer as input:
            n -> left = new RBtreeNode(in, n);
            insert_fixup(n -> left); // call to insert_fixup on n's left
        }
        else
        {
            insert_h(n -> left, in); // call to insert_h on n's left and record pointer in
        }
    }
    else // for right:
    {
        if (n -> right == NULL)
        {
            n -> right = new RBtreeNode(in, n);
            insert_fixup(n -> right);
        }
        else
        {
            insert_h(n -> right, in);
        }
    }
}

/*
 * ASSUMPTIONS FOR REMOVE_FIXUP: n is black and the only property that is possibly violated is that
 * after the node deletes, all the paths going through n have one fewer black node
 * than before.
 */
void RBRecordDict :: remove_fixup(RBtreeNode *n)
{
    if (n == root) // CASE 1: n is the root
    {
        return; // every path on the tree has one fewer black node so RB properties are rejected
    }

    // what to do next depends on the color of sibling and its children
    RBtreeNode *s = sibling(n);

    if (s -> color == Red) // CASE 2: s is red, so n's parent is black and s's children are black
    {
        n -> parent -> color = Red; // color n's parent red
        s -> color = Black; // color s black

        if (n -> parent -> left == n) // if n is left of parent
        {
            rotate_left(n -> parent); // perform left rotation on n's parent
        }
        else
        {
            rotate_right(n -> parent); // perform right rotation on n's parent
        }
        s = sibling(n); // n sibling is black so needs to be updated
        // the problem isn't solved, but now in all remaining cases, s is black
    }
    // CASE 3: if n's parent is red, s is black, and s's left and right are both black
    if (n -> parent -> color == Red && s -> color == Black && color(s -> left) == Black && color(s -> right) == Black)
    {
        n -> parent -> color = Black;
        s -> color = Red;
        // a black node was added to every path going through n, so nothing changed for other paths.
        return;
    }
    if (n -> parent -> right == s || n -> parent -> left == s) // CASE 4: if n's parent's right or left is s
    {
        if (s == n -> parent -> right && color(s -> left) == Red && color(s -> right) == Black) // case left
        {
            s -> color = Red; // color s red
            s -> left -> color = Black; // color s's left black
            rotate_right(s); // perform a right rotation on s
        }
        else if (s == n -> parent -> left && color(s -> right) == Red && color(s -> left) == Black) // case right
        {
            s -> color = Red; // color s red
            s -> right -> color = Black; // color s's right black
            rotate_left(s); // perform a left rotation on s
        }

        s = sibling(n); // brings function to CASE 5
    }
    if (n -> parent -> right == s || n -> parent -> left == s) // CASE 5: if n's parent right or left is s
    {
        s -> color = n -> parent -> color; // s takes parent's color
        n -> parent -> color = Black; // color parent black

        if (n == n -> parent -> left && color(s -> right) == Red) // if n is parent's left and s's right is red; case left.
        {
            s -> right -> color = Black; // color s's right black
            rotate_left(n -> parent); // perform left rotation on n's parent
            return;
        }
        else if (n == n -> parent -> right && color(s -> left) == Red) // if n is parent's right and s's left is red; case right.
        {
            s -> left -> color = Black; // color s's left black
            rotate_right(n -> parent); // perform right rotation on n's parent
            return;
        }
    }
    // CASE 6: last case where everyone is black
    if (n -> color == Black && n -> parent -> color == Black && s -> color == Black && s -> left -> color == Black && s -> right -> color == Black)
    {
        s -> color = Red; // color s red
        // now every path going through p is missing a black node, and p is black
        remove_fixup(n -> parent); // call to remove_fixup on n's parent
    }
}

void RBRecordDict :: inOrder_help(RBtreeNode *leaf)
{
    if (leaf == NULL)
    {
        return; // stops without doing anything
    }
    else // if leaf is not NULL
    {
        inOrder_help(leaf -> left); // recursively visit left
        outputFile << leaf -> data -> fileString() << endl; // visit current node
        inOrder_help(leaf -> right); // recursively visit right
    }
}

// performs an in-order traversal
void RBRecordDict :: inOrderTraversal()
{
    inOrder_help(root); // call to inOrder_help on root
}

void RBRecordDict :: preOrder_help(RBtreeNode *leaf)
{
    if (leaf == NULL)
    {
        return; // stops without doing anything
    }
    else // if leaf is not NULL
    {
        outputFile << leaf -> data -> fileString() << endl; // visit current node
        preOrder_help(leaf -> left); // recursively visit left
        preOrder_help(leaf -> right); // recursively visit right
    }
}

// performs a pre-order traversal
void RBRecordDict :: preOrderTraversal()
{
    preOrder_help(root); // call to preOrder_help on root
}

void RBRecordDict :: postOrder_help(RBtreeNode *leaf)
{
    if (leaf == NULL)
    {
        return; // stops without doing anything
    }
    else // if leaf is not NULL
    {
        postOrder_help(leaf -> left); // recursively visit left
        postOrder_help(leaf -> right); // recursively visit right
        outputFile << leaf -> data -> fileString() << endl; // visit current node
    }
}

// performs a post-order traversal
void RBRecordDict :: postOrderTraversal()
{
    postOrder_help(root); // call to postOrder_help on root
}

/*
 * public function takes a pointer to a record in and inserts it in
 * the Red-Black tree
 */
void RBRecordDict :: insert(record *in)
{
    if (root == NULL)
    {
        root = new RBtreeNode(in); // makes the root a new RBtreeNode
        root -> color = Black; // color the root black
    }
    else
    {
        insert_h(root, in); // call to insert_h on root and record pointer
    }
}

/*
 * public function that takes string w, searches for it in the Red-Black
 * tree and returns a pointer to the RBtreeNode whose record's barcode member is
 * equal to w. the function returns NULL if no such RBtreeNode is found.
 */
RBtreeNode* RBRecordDict :: search(string w)
{
    return search_help(w, root); // simply calls search_help on the root
}

/*
 * a public function that takes string w and removes the node in the tree whose
 * dict entry's word member is equal to w. if no such node exists, this function does
 * nothing
 */
void RBRecordDict :: remove(string w)
{
    // inDanger is node that may be deleted
    RBtreeNode *dataNode, *inDanger; // declaration of RBtreeNode pointers
    dataNode = search(w); // dataNode is what's returned by search on w

    if (dataNode == NULL)
    {
        return; // cannot remove because dataNode is null
    }
    if (dataNode -> left == NULL || dataNode -> right == NULL) // if dataNodes left and right are NULL
    {
        inDanger = dataNode; // the node that may be deleted (inDanger) is now dataNode
    }
    else
    {
        inDanger = successor(dataNode); // inDanger is call to successor on dataNode
        dataNode -> data = inDanger -> left -> data; // the data in dataNode is inDanger's left's data
    }
    if (inDanger -> left != NULL) // if inDanger's left is not NULL
    {
        inDanger -> data = inDanger -> left -> data; // inDanger's data is inDanger's left's data
        delete inDanger -> left; // delete inDanger's left
        inDanger -> left = NULL; // inDanger's left is NULL
        return;
    }
    if (inDanger -> right != NULL) // if inDanger's right is not NULL
    {
        inDanger -> data =  inDanger -> right -> data; // inDanger's data is inDanger's right's data
        delete inDanger -> right; // delete inDanger's right
        inDanger -> right = NULL; // inDanger's right is NULL
        return;
    }
    if (inDanger -> color == Black) // if inDanger is black
    {
        remove_fixup(inDanger); // call remove_fixup on inDanger
    }
    if (inDanger -> parent == NULL) // if the parent of inDanger is NULL
    {
        root = NULL; // set root to NULL
    }
    else if (inDanger -> parent -> left == inDanger) // if inDanger's parent's left is inDanger
    {
        inDanger -> parent -> left = NULL; // set inDanger's parent's left to NULL
    }
    else
    {
        inDanger -> parent -> right = NULL; // set inDanger's parent's right to NULL
    }
    delete inDanger; // delete inDanger
}

/*
 * a public function that takes a string filename as input, asks the user if they want
 * to use a preorder, inorder, or postorder traversal, and then prints all the records
 * in the file in the order requested by the user.
 */
void RBRecordDict :: toFile(string filename)
{
    outputFile.open(filename.c_str()); // open file for output
    string userChoice; // used for user input of choice for what type of traversal to use
    bool prompt = false; // used for checking whether user input is correct

    if (outputFile.is_open()) // if the output file is successfully created
    {
        cout << "Enter pre to use a preorder traversal, in for an inorder traversal, or post for a postorder traversal:" << endl;
        cin >> userChoice; // user input userChoice for which type of traversal to run

        while (prompt == false) // continuously prompt the user until a correct input is given
        {
            if (userChoice == "pre") // the user chose a preorder traversal
            {
                preOrderTraversal(); // call to preOrderTraversal
                prompt = true; // the user entered a correct prompt, exit the while loop
            }
            else if (userChoice == "in") // the user chose an inorder traversal
            {
                inOrderTraversal(); // call to inOrderTraversal
                prompt = true;
            }
            else if (userChoice == "post") // the user chose a postorder traversal
            {
                postOrderTraversal(); // call to postOrderTraversal
                prompt = true;
            }
            else // the user did not enter a correct choice
            {
                cout << endl << "You entered an incorrect choice!" << endl;
                cout << "Enter pre to use a preorder traversal, in for an inorder traversal, or post for a postorder traversal:" << endl;
                cin >> userChoice; // prompt user for a correct choice again
            }
        }

        outputFile.close(); // close the output file
    }
    else // the output file could not be successfully created
    {
        cout << "The output file was not successfully created!" << endl;
    }
}

// public constructor that sets root to NULL
RBRecordDict :: RBRecordDict()
{
    root = NULL;
}

// public deconstructor that deletes all nodes in the tree
RBRecordDict :: ~RBRecordDict()
{
    destroy_tree(root); // call to destroy_tree on the root
}
