/* 
 * File:   RowAry
 * Author: Jose Sanchez
 * Created on September 1, 2016, 8:36 PM
 * Purpose:  Dynamic Object Arrays
 */

//User Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//User Libraries
#include "RowAray.h"

//constructor
RowAray::RowAray(int a)
{
    size=a;
    rowData = new int[size];
    for(int i=0; i<size; i++){
        rowData[i]=10+rand()%(89);
    }
}

//destructor 
RowAray::~RowAray()
{
    
}