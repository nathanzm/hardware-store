#include "record.h"

// constructor of record that initializes barcode, name, price, and quantity to c, n, p, and q
record :: record(string c, string n, float p, int q){barcode = c; name = n; price = p; quantity = q;}


// toString function allows for elements of the record to be displayed nicely
string record :: toString()
{
    ostringstream convert; // makes variable convert of ostringstream
    convert << "Barcode: " << barcode << " Name: " << name << " Price: " << price << " Quantity: " << quantity; // put all in variable convert
    return convert.str(); // make variable convert a string
}

// fileString function that takes no input and returns string that contains barcode, name, price, and quantity all separated by a space
string record :: fileString()
{
    ostringstream convert; // makes variable convert of ostringstream
    convert << barcode << " " << name << " " << price << " " << quantity; // put all in variable convert
    return convert.str(); // make variable convert a string
}

// takes no input and returns string that contains the barcode
string record :: getBarcode()
{
    return barcode;
}

/*
 * sell takes an integer as input and decreases quantity by the input integer but only if the quantity
 * minus the input is greater than zero. this function then returns the product of the input and
 * the price sold if it successfully decreased the quantity as well as telling the user if the
 * quantity was insufficient.
 */
float record :: sell(int integer)
{
    if ((quantity - integer) > 0) // if quantity is sufficient
    {
        quantity = quantity - integer; // subtract input from quantity
        return integer * price; // return product of integer and price
    }
    else // the quantity is insufficient
    {
        return 0;
    }
}

/*
 * the next 6 overloaded operators compare the barcode given
 * to the barcode of the element you're sitting in. the barcode
 * given is either an instance of record or a string, which is
 * why there are two functions for each overloaded operator (each
 * one takes either a string or record as input).
 */
bool record :: operator ==(record instance) // record as input
{
    if (instance.barcode == barcode)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool record :: operator ==(string str) // string as input
{
    if (str == barcode)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool record :: operator <(record instance) // record as input
{
    if (barcode < instance.barcode)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool record :: operator <(string str) // string as input
{
    if (barcode < str)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool record :: operator >(record instance) // record as input
{
    if (barcode > instance.barcode)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool record :: operator >(string str) // string as input
{
    if (barcode > str)
    {
        return true;
    }
    else
    {
        return false;
    }
}
