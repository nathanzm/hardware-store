#include "HTrecordDict.h"

/*
 * the function PromptUser goes through a series of prompts to the console asking
 * the user which option they would like to execute. the function only accepts
 * a user input of the numbers 0 through 6 in string form and will continuously
 * prompt the user for a correct input if they did not do otherwise. once the user
 * enters a correct input, the function returns that string.
 */
string PromptUser()
{
    string chooseOption; // user input for options (options are described in the main function below)

    while (chooseOption != "1" && chooseOption != "2" && chooseOption != "3" && chooseOption != "4" && chooseOption != "5" && chooseOption != "6" && chooseOption != "7" && chooseOption != "0")
    {
        cout << endl << "Would you like to read a file (1)," << endl;
        cout << "manually add an entry (2)," << endl;
        cout << "search for a barcode in the inventory (3)," << endl;
        cout << "sell an item (4)," << endl;
        cout << "remove a barcode from the inventory (5)," << endl;
        cout << "write the inventory to a file (6)," << endl;
        cout << "or end the program? (0)" << endl << endl;
        cin >> chooseOption; // user input chooseOption
        if (chooseOption != "1" && chooseOption != "2" && chooseOption != "3" && chooseOption != "4" && chooseOption != "5" && chooseOption != "6" && chooseOption != "7" && chooseOption != "0")
        {
            cout << "You entered an invalid option choice, try again!" << endl;
        }
    }
    return chooseOption; // option chosen through user input
}

int main()
{
    inventory *myInventory; // declare instance of inventory to use for all data structures
    string userChoice; // user input choice of data structure for inventory as well as options
    string filename; // user input file name
    // the next 4 variables are used for manually inserting records in option 2
    string barcode;
    string name;
    float price;
    int quantity;
    int sizeOfHash; // used for user input of hash table size

    // continuously prompt the user for the correct input for selecting which data structure to use:
    while (userChoice != "L" && userChoice != "R" && userChoice != "H")
    {
        cout << "Is the inventory going to use a linked list (L), a red-black tree (R), or a hash table (H)?" << endl;
        cin >> userChoice;
        if (userChoice != "L" && userChoice != "R" && userChoice != "H")
        {
            cout << endl << "You entered an invalid choice, try again!" << endl;
        }
    }

    if (userChoice == "L") // the user chose linked-list implementation
    {
        myInventory = new inventory(new listRecordDict); // declare inventory as a listRecordDict

        while (userChoice == "L") // go through all options continuously
        {
            string prompt = PromptUser(); // call to PromptUser() for which option to execute

            /*
             * OPTION 1: Read a file. This will enter all entries of that file into the inventory.
             */
            if (prompt == "1")
            {
                cout << endl << "Enter the name of the file you want to read:" << endl;
                cin >> filename; // user input an input file name with directory (if necessary)
                myInventory -> readFile(filename); // call to readFile function
            }
            /*
             * OPTION 2: Manually add an entry. This option will prompt the user for all the fields
             * necessary in a record, create a record with these elements, and insert it into the
             * inventory.
             */
            if (prompt == "2")
            {
                cout << "Enter a barcode:" << endl;
                cin >> barcode;
                cout << "Enter a name:" << endl;
                cin >> name;
                cout << "Enter a price:" << endl;
                cin >> price;
                cout << "Enter a quantity:" << endl;
                cin >> quantity;
                record *addRecord = new record(barcode, name, price, quantity); // create the record
                myInventory -> add(addRecord); // add the record to the inventory
            }
            /*
             * OPTION 3: This option will prompt the user for a barcode and search the inventory
             * for that barcode.
             */
            if (prompt == "3")
            {
                cout << "Enter a barcode to search for:" << endl;
                cin >> barcode;
                myInventory -> search(barcode); // call to search on the user entered barcode
            }
            /*
             * OPTION 4: This option will prompt the user for a barcode and a quantity and attempt to
             * sell the quantity of that item.
             */
            if (prompt == "4")
            {
                cout << "Enter a barcode:" << endl;
                cin >> barcode;
                cout << "Enter a quantity:" << endl;
                cin >> quantity;
                myInventory -> sell(barcode, quantity); // call to sell on entered item barcode and quantity
            }
            // OPTION 5: This option will prompt the user for a barcode and remove that barcode from the inventory.
            if (prompt == "5")
            {
                cout << "Enter a barcode:" << endl;
                cin >> barcode;
                myInventory -> remove(barcode);
            }
            // OPTION 6: This option will ask the user for a file name and use the toFile function to output to that file
            if (prompt == "6")
            {
                cout << "Enter a filename:" << endl;
                cin >> filename;
                myInventory -> toFile(filename);
            }
            // OPTION 0: This option will end the program and delete the inventory.
            if (prompt == "0")
            {
                delete myInventory; // delete the inventory
                break; // break out of the while loop and end the program
            }
        }
    }

    // THE OPTIONS IN THE NEXT SEGMENT WORK THE SAME AS THE PREVIOUS BUT WITH A RED-BLACK TREE
    if (userChoice == "R") // the user chose red-black tree implementation
    {
        myInventory = new inventory(new RBRecordDict); // declare inventory as RBRecordDict

        while (userChoice == "R")
        {
            string prompt = PromptUser();

            if (prompt == "1") // option 1:
            {
                cout << endl << "Enter the name of the file you want to read:" << endl;
                cin >> filename;
                myInventory -> readFile(filename);
            }
            if (prompt == "2") // option 2:
            {
                cout << "Enter a barcode:" << endl;
                cin >> barcode;
                cout << "Enter a name:" << endl;
                cin >> name;
                cout << "Enter a price:" << endl;
                cin >> price;
                cout << "Enter a quantity:" << endl;
                cin >> quantity;
                record *addRecord = new record(barcode, name, price, quantity);
                myInventory -> add(addRecord);
            }
            if (prompt == "3") // option 3:
            {
                cout << "Enter a barcode to search for:" << endl;
                cin >> barcode;
                myInventory -> search(barcode);
            }
            if (prompt == "4") // option 4:
            {
                cout << "Enter a barcode:" << endl;
                cin >> barcode;
                cout << "Enter a quantity:" << endl;
                cin >> quantity;
                myInventory -> sell(barcode, quantity);
            }
            if (prompt == "5") // option 5:
            {
                cout << "Enter a barcode:" << endl;
                cin >> barcode;
                myInventory -> remove(barcode);
            }
            if (prompt == "6") // option 6:
            {
                cout << "Enter a filename:" << endl;
                cin >> filename;
                myInventory -> toFile(filename);
            }
            if (prompt == "0") // option 0:
            {
                delete myInventory;
                break;
            }
        }
    }

    // THE OPTIONS IN THE NEXT SEGMENT WORK THE SAME AS THE PREVIOUS BUT WITH A HASH TABLE
    if (userChoice == "H") // the user chose hash table implementation
    {
        cout << endl << "Enter a positive integer for the size of the hash table:" << endl;
        cin >> sizeOfHash; // user input the size of the hash table

        myInventory = new inventory(new HTrecordDict(sizeOfHash)); // declare inventory as HTrecordDict with size entered by user

        while (userChoice == "H")
        {
            string prompt = PromptUser();

            if (prompt == "1") // option 1:
            {
                cout << endl << "Enter the name of the file you want to read:" << endl;
                cin >> filename;
                myInventory -> readFile(filename);
            }
            if (prompt == "2") // option 2:
            {
                cout << "Enter a barcode:" << endl;
                cin >> barcode;
                cout << "Enter a name:" << endl;
                cin >> name;
                cout << "Enter a price:" << endl;
                cin >> price;
                cout << "Enter a quantity:" << endl;
                cin >> quantity;
                record *addRecord = new record(barcode, name, price, quantity);
                myInventory -> add(addRecord);
            }
            if (prompt == "3") // option 3:
            {
                cout << "Enter a barcode to search for:" << endl;
                cin >> barcode;
                myInventory -> search(barcode);
            }
            if (prompt == "4") // option 4:
            {
                cout << "Enter a barcode:" << endl;
                cin >> barcode;
                cout << "Enter a quantity:" << endl;
                cin >> quantity;
                myInventory -> sell(barcode, quantity);
            }
            if (prompt == "5") // option 5:
            {
                cout << "Enter a barcode:" << endl;
                cin >> barcode;
                myInventory -> remove(barcode);
            }
            if (prompt == "6") // option 6:
            {
                cout << "Enter a filename:" << endl;
                cin >> filename;
                myInventory -> toFile(filename);
            }
            if (prompt == "0") // option 0:
            {
                delete myInventory;
                break;
            }
        }
    }

    return 0;
}
