#include "inventory.h"

/* the following constructor allows user to choose
 * what type of recordDict the inventory will use.
 */
inventory :: inventory(recordDict* pointer)
{
    dict = pointer; // initialize dict to pointer
}

inventory :: ~inventory()
{
    delete dict; // calls destructor;
}

/*
 * takes a string as input and queries the search function of its
 * recordDict on that input. the function returns a pointer to a
 * container and whether the pointer is null.
 */
void inventory :: search(string str)
{
    container* searched = dict -> search(str); // call to search function on input

    if (searched == NULL) // if searched is null, it's not there
    {
        cout << "Barcode not found." << endl;
    }
    else
    {
        // otherwise return the data in searched formatted by toString()
        cout << searched -> data -> toString() << endl;
    }
}

/*
 * the sell function takes a string and an integer as input and queries
 * the search function on its recordDict on that input and returns a pointer
 * to a container. if that pointer is null, an according message is printed
 * to the console. if the pointer is not null, the item will be sold accordingly:
 */
void inventory :: sell(string str, int num)
{
    float returnedFloat;
    container* searched = dict -> search(str); // call to search on str

    if (searched == NULL) // if the searched item is NULL then it doesn't exist
    {
        cout << "Barcode not found." << endl;
    }
    else if (searched != NULL)
    {
        // call to sell function of record that is in container using the inputted integer
        returnedFloat = searched -> data -> sell(num);
        if (returnedFloat == 0)
        {
            cout << "That quantity of item " << str << " is not available." << endl;
        }
        else
        {
            cout << num << " of item " << str << " sold for " << returnedFloat << "." << endl;
        }
    }
}

/*
 * add function takes a pointer to a record as input and uses the insert
 * function from the recordDict to insert the record into the tree.
 */
void inventory :: add(record* item)
{
    dict -> insert(item);
}

/*
 * remove function takes a string as input and uses the remove function from
 * the recordDict to remove the record corresponding to that string from the
 * recordDict.
 */
void inventory :: remove(string str)
{
    dict -> remove(str);
}

/*
 * readFile function takes a string filename as input and opens that file
 * (if it exists), reads it, and then enters each record contained in the
 * file into the recordDict.
 */
void inventory :: readFile(string filename)
{
    ifstream inputFile; // instance of input file
    inputFile.open(filename.c_str()); // opens file for reading
    // the next 4 variables are for reading in from the file
    string barcode;
    string name;
    float price;
    int quantity;
    if (inputFile.is_open()) // if the input file exists/is open
    {
        while (!inputFile.eof()) // stop this while when the end of the file is reached
        {
            // read into each variable from the file
            inputFile >> barcode;
            inputFile >> name;
            inputFile >> price;
            inputFile >> quantity;
            // now create a new record with these variables:
            record *addRecord = new record(barcode, name, price, quantity);
            add(addRecord); // add that record into the recordDict
        }

    inputFile.close(); // closes file for reading
    }
    else // the user entered an invalid input file
    {
        cout << "You have entered an invalid file or directory!" << endl;
    }
}

// toFile takes filename as an input and simply calls the function toFile from recordDict using filename
void inventory :: toFile(string filename)
{
    dict -> toFile(filename);
}
