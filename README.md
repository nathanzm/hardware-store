# Inventory
## Description:
As a project for my Algorithms class at Wheaton College, I made a program that simulates software for interacting with the inventory of a hardware store. The inventory is implemented with three different data structures: a linked list, red-black tree, or hash table.

## Usage:
The program starts by prompting the user for which type of data structure to implement the inventory in. Sample input files with items to add to the inventory are located in the "input" directory. 

There are then four main functions: searching for a bar code, selling an item, adding an item to the inventory, and removing an item from the inventory. All of these can be attained through the following options:

- **Option 0:** This deletes the current inventory and ends the program.

- **Option 1:** Read a file. Prompts the user for the name of a file and enters all of the entries of that file into the inventory.

- **Option 2:** Manually add an entry. Prompts the user for all the necessary fields of an item and inserts that item into the inventory.

- **Option 3:** Search for a barcode in the inventory. Prompts the user for a barcode of an item and returns the item with its details if it exists.

- **Option 4:** Sell an item. Prompts the user for a barcode and quantity and sells the quantity of that item. If the quantity is unavailable, the user will be alerted.

- **Option 5:** Remove a barcode from the inventory. Prompts the user for a barcode of an item and removes that item from the inventory if it exists.

- **Option 6:** Write the current inventory to a file. Prompts the user for a file name to write the contents to.