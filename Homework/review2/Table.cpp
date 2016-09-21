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

#include "Table.h"

//table constructor
Table::Table(unsigned int r,unsigned int c)
{
    szRow=r;
    szCol=c;
    columns = new RowAray*[szRow];

    //create 1-d array of objects, within objects is an array. 
    for(int i=0; i<szRow; i++)
    {
        columns[i] = new RowAray(szCol);
    }           
};

//table constructor with another table
Table::Table(const Table &Tab2)
{        
    szCol=Tab2.getSzCol();
    szRow=Tab2.getSzRow();

    columns = new RowAray*[szRow];

    //create 1-d array of objects, within objects is an array. 
    for(int i=0; i<szRow; i++)
    {
        columns[i] = new RowAray(szCol);
    }  


    for(int i=0; i<szRow; i++)
    {
        for(int j=0; j<szCol; j++)
        {
            setData(i, j, Tab2.columns[i]->getData(j));
        }
    }

};

//deconstructor
Table::~Table()
{
    delete columns;
};

//returns data at r c 
int Table::getData(int r ,int c)const 
{
    return columns[r]->getData(c);
};

//sets the data at r c with number num
void Table::setData(int r,int c,int num)
{

};