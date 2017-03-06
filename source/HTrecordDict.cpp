#include "HTrecordDict.h"

/*
 * this protected hash function takes a string as input and hashes it
 * into the array of linked lists
 */
int HTrecordDict :: hash(string str)
{
    int h = b; // assigns h to random integer b

    for (int i = 0; i < str.length(); i++) // from i to the length of inputted string
    {
        h = (h * a + str[i]) % size; // hashes (spreads out randomly) the string
    }
    return h; // return index
}

/*
 * public function insert that takes a pointer to a record and uses hash on the barcode
 * of that record and inserts the record at the beginning of the list H[h] where h is
 * the index returned by the barcode.
 */
void HTrecordDict :: insert(record *in)
{
    int h = hash(in -> getBarcode()); // hashed barcode of record is h

    cell *newCell; // pointer to create new node

    if (H[h] == NULL) // if the list is empty at given position in hash table
    {
        newCell = new cell(in); // create a new cell
        H[h] = newCell; // given position in hash table is the new cell
    }
    else // the list isn't empty, insert newNode after first
    {
        newCell = new cell(in); // create new cell; constructor sets previous and next to NULL
        newCell -> next = H[h]; // next of the new cell is H[h]
        H[h] -> previous = newCell; // previous of H[h] is new cell
        H[h] = newCell; // given position in hash table is now the new cell
    }
}

/*
 * public function search that takes a string w, hashes that string to get an index h,
 * and then searches the linked list hanging from H[h] for a cell with a record that has
 * w for its barcode. if such a record is found, the cell containing is returned, otherwise
 * the function just returns NULL.
 */
cell* HTrecordDict :: search(string w)
{
    int h = hash(w);
    cell *current; //pointer to traverse the list
    current = H[h]; // start current at the beginning of linked list (H[h])
    while (current != NULL)
    {
        if (current -> data -> operator==(w)) // overloaded operator usage to check if current's data has w
        {
            return current; // return pointer to cell that has member equal to w
        }
        else
        {
            current = current -> next; // advance current to the next cell
        }
    }

    return NULL; // w was not found in the list
}

/*
 * public function remove that takes a string w, hashes that string to get an index
 * h, searches the linked list hanging from H[h] for a cell with a record that has w
 * for its barcode. if such a cell is found, it is removed from the linked list, otherwise
 * no such cell was found and there's nothing to do.
 */
void HTrecordDict :: remove(string w)
{
    int h = hash(w); // get index h by hashing w
    cell* toDelete = search(w); // pointer to cell toDelete is call to search on w

    if (toDelete == NULL) // doesn't exist if NULL
    {
        cout << "No such node exists!" << endl;
    }
    else if (toDelete == H[h] && toDelete -> next == NULL) // if toDelete is at H[h] and its next is NULL
    {
        H[h] = NULL; // set H[h] to NULL
        toDelete -> next = NULL; // set toDelete's next to NULL
        delete toDelete;
    }
    else if (toDelete == H[h] && toDelete -> next != NULL) // if toDelete is at H[h] and its next is not NULL
    {
        H[h] = H[h] -> next; // advance first node in linked list (at H[h]) to next
        H[h] -> previous = NULL; // update previous pointer of H[h] to NULL
        delete toDelete;
    }
    else if (toDelete -> next == NULL && toDelete != H[h]) // if toDelete's next is NULL and toDelete is after the first node
    {
        toDelete -> next = toDelete -> next -> previous; // toDelete's next is toDelete's next's previous
        toDelete -> next -> next = NULL; // toDelete's next's next is NULL
        delete toDelete;
    }
    else
    {
        toDelete -> previous -> next = toDelete -> next; // toDelete's previous's next is toDelete's next
        toDelete -> next -> previous = toDelete -> previous; // toDelete's next's previous is toDelete's previous
        delete toDelete;
    }
}

/*
 * public function toFile that takes a string filename as input and goes through
 * the whole hash table (each index), writes to a file all the records contained
 * in the linked list hanging from H at each index.
 */
void HTrecordDict :: toFile(string filename)
{
    cell* current; // declaration of cell pointer current
    ofstream outputFile; // declaration of outputFile
    outputFile.open(filename.c_str()); // open file for output

    if (outputFile.is_open()) // if the output file is successfully created
    {
        for (int i = 0; i < size; i++)
        {
            current = H[i]; // start current at H[i]

            while (current != NULL) // while current doesn't reach NULL
            {
                // write the data in current formatted by fileString to the output file
                outputFile << (current -> data) -> fileString() << endl;
                current = current -> next; //advance current to next
            }
        }

        outputFile.close(); // close the output file
    }
    else // the output file wasn't successfully created
    {
        cout << "The output file was not successfully created!" << endl;
    }
}

/*
 * this public constructor takes an int as input and initializes size to the
 * inputted integer, allocate an array of that size and assign that to H.
 * it then initializes the content of every index to NULL and initializes
 * integers a and b to random values between 1 and the size of H.
 */
HTrecordDict :: HTrecordDict(int num)
{
    size = num; // assign size to num
    H = new cell*[size]; // H is an array of cell pointers of size size

    for (int i = 0; i < size; i++)
    {
        H[i] = NULL; // initialize every location in H to null
    }

    a = rand() % size + 1; // a is a random integer between 1 and size
    b = rand() % size + 1; // b is a random integer between 1 and size
}

/*
 * this public destructor goes through every index in H and deletes every cell
 * in every linked list hanging from H, then deletes the array itself.
 */
HTrecordDict :: ~HTrecordDict()
{
    for (int i = 0; i < size; i++)
    {
        cell *first, *temp; //pointer to deallocate the memory occupied by the node
        first = H[i]; // start first at H[i]

        while (first != NULL) //while there are nodes in the list
        {
            temp = first; //set temp to the current node
            first = first -> next; //advance first to the next node
            delete temp; //deallocate the memory occupied by temp
        }
    }
    delete H; // delete the array H
}
