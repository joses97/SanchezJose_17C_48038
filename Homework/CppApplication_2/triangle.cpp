/* 
 * File:   traingle
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
#include "Triangle.h"

Triangle::Triangle(int a)
{
    szRow=a;
    records = new RowAray*[szRow];
    
    //create 1-d array of objects, within objects is an array. 
    for(int i=0; i<szRow; i++)
    {
        records[i] = new RowAray(szRow);
    }
}

Triangle::getData(int r, int c)
{
    return records[r]->getData(c);
}

Triangle::~Triangle()
{
    
}