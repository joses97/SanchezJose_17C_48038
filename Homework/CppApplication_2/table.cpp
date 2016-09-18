/* 
 * File:   Table
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
#include "Table.h"

Table::Table(int r, int c)
{
    szRow=r;
    szCol=c;
    records = new RowAray*[szRow];
    
    //create 1-d array of objects, within objects is an array. 
    for(int i=0; i<szRow; i++)
    {
        records[i] = new RowAray(szCol);
    }
    
    //fill records[szRow] with information
    
}

int Table::getData(int row , int col)
{
    return records[row]->getData(col);
}

Table::~Table()
{
    
}
