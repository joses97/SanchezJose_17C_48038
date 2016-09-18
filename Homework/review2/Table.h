/* 
 * File:   Table.h
 * Author: Dr. Mark E. Lehr
 * Created on February 25, 2016, 8:54 AM
 * Specification for the Table
 */

#ifndef TABLE_H
#define	TABLE_H

#include "AbsTabl.h"

class Table:public AbsTabl{
    public:
        Table(unsigned int r,unsigned int c)
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
        Table(const Table &)
        {
            
        };
        virtual ~Table();
        int getSzRow()const {return szRow;}
        int getSzCol()const {return szCol;}
        int getData(int,int)const;
        void setData(int,int,int);
};

#endif	/* TABLE_H */