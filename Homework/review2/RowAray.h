/* 
 * File:   RowAray.h
 * Author: Dr. Mark E. Lehr
 * Created on February 25, 2016, 8:54 AM
 * Specification for the RowAray
 */

#ifndef ROWARAY_H
#define	ROWARAY_H

#include "AbsRow.h"

class RowAray:public AbsRow{
    public:
        RowAray(unsigned int r)
        {
            size=r;
            rowData = new int[r];
            
            for(int i=0; i<size; i++)
            {
                rowData[i]=10+rand()%(89);
            }
        };
        virtual ~RowAray()
        {
            delete rowData;
        };
        int getSize()const{return size;}
        int getData(int i)const{
            if(i>=0&&i<size)return rowData[i];
            else return 0;}
        void setData(int r ,int c)
        {
            
        };
};

#endif	/* ROWARAY_H */