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
        Table(unsigned int ,unsigned int );
        
        
        Table(const Table &Tab2);
        
        int getSzRow()const {return szRow;}
        int getSzCol()const {return szCol;}
        
        virtual ~Table();
               
        int getData(int r ,int c)const;
        
        void setData(int r,int c,int num);
};

#endif	/* TABLE_H */