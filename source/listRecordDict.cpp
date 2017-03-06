#include "listRecordDict.h"

listRecordDict :: listRecordDict() // constructor that sets first and last to NULL
{
    first = NULL;
    last = NULL;
}

listRecordDict :: ~listRecordDict() // destructor that deletes all cells in linked list
{
    cell *temp; //pointer to deallocate the memory occupied by the node
    while (first != NULL) //while there are nodes in the list
    {
        temp = first; //set temp to the current node
        first = first -> next; //advance first to the next node
        delete temp; //deallocate the memory occupied by temp
    }
    last = NULL; //initialize last to NULL
}

/*
 * This function insert takes a pointer to a record in and inserts it at the end of
 * the list. This function assumes that the user will not insert an element that is
 * already there.
 */
void listRecordDict :: insert(record *in)
{
    cell *newCell; // pointer to create new node

    if (first == NULL) // if the list is empty, newNode is both first and last node
    {
        newCell = new cell(in); // create new cell
        first = newCell; // set first to new cell
        last = newCell; // set last to new cell
    }
    else // the list isn't empty, insert newNode after last
    {
        newCell = new cell(in, last); // next is NULL, data is in, previous is last
        last -> next = newCell; // insert newNode after last
        last = newCell; // make the last point to the actual last node in the list
    }
}

/*
 * A public function search that takes a string w, searches for it in the list
 * and returns a pointer to the cell whose record’s barcode member is equal to w.
 * The function returns NULL if no such cell is found.
 */
cell* listRecordDict :: search(string w)
{
    cell *current; //pointer to traverse the list
    current = first; // start current at the beginning
    while (current != NULL) // while not at the end of the list
    {
        if (current -> data -> operator==(w)) // if searched item is found:
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
 * A public function remove that takes a string w as input and removes the node
 * in set of data whose dict-entry's word member is equal to w. If no such node
 * exists, the function does nothing.
 */
void listRecordDict :: remove(string w)
{
    cell* toDelete = search(w); // call to search on w
    if (toDelete == NULL) // doesn't exist if NULL
    {
        cout << "No such node exists!" << endl;
    }
    else if (toDelete == first && toDelete == last) // if toDelete is the only thing in the list
    {
        first = NULL; // set first to null
        last = NULL; // set last to null
        delete toDelete;
    }
    else if (toDelete == first && toDelete != last) // if toDelete is the first but not the last
    {
        first = first -> next; // advance first to next cell
        first -> previous = NULL; // update previous pointer of new first to NULL
        delete toDelete;
    }
    else if (toDelete == last && toDelete != first) // if toDelete is the last but not the first
    {
        last = last -> previous; // update last to the previous
        last -> next = NULL; // set last's next to null
        delete toDelete;
    }
    else // if toDelete is somewhere in between first and last
    {
        // update the pointers of the cells preceding and following toDelete so that they bypass toDelete
        toDelete -> previous -> next = toDelete -> next;
        toDelete -> next -> previous = toDelete -> previous;
        delete toDelete;
    }
}

/*
 * A public function toFile that takes a string filename as input and then writes
 * to the file all the contents of all cells in the list using the fileString()
 * function of each record.
 */
void listRecordDict :: toFile(string filename)
{
    cell* current = first; // start current at first
    ofstream outputFile; // outputFile declaration
    outputFile.open(filename.c_str()); // open file for output

    if (outputFile.is_open()) // if the file is successfully opened
    {
        while (current != NULL) // while current is not at the end of the list
        {
            // write to the file the data within the current cell and format it with fileString()
            outputFile << (current -> data) -> fileString() << endl;
            current =  current -> next; // advance current to the next node
        }
        outputFile.close(); // close the output file
    }
    else // the output file wasn't successfully created
    {
        cout << "The output file was not successfully created!" << endl;
    }
}
