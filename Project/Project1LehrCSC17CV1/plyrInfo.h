/* 
 * File:   playrInfo.h
 * Author: Jose Sanchez
 * Purpose: hold player info
 * Created on June 4th 2016
 */

//System libraries
#include <string>
using namespace std;

//User libraries

//define 
#ifndef PLYRINFO_H
#define PLYRINFO_H


//constant for the size of the 2d character array
const int SIZEI=10;

//create structure to keep track of user info
struct info
{
    char arr[SIZEI][SIZEI];
    string names;
};

#endif /* PLYRINFO_H */

