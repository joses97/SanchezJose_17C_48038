/* 
 * File:   Table.cpp
 * Author: Jose Sanchez
 * Created on September  2016, 
 * Purpose:  Dynamic Object Arrays
 */

//User Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

#include "RowAray.h"

RowAray::RowAray(unsigned int r)
{
    size=r;
    rowData = new int[r];

    for(int i=0; i<size; i++)
    {
        rowData[i]=10+rand()%(89);
    }
}


