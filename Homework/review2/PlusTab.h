/* 
 * Author: Dr. Mark E. Lehr
 * Created on February 25, 2016, 8:54 AM
 * Specification for the Table addition operator
 */

#ifndef PLUSTAB_H
#define	PLUSTAB_H

#include "Table.h"

class PlusTab:public Table{
    public:
        PlusTab(unsigned int r,unsigned int c):Table(r,c)
        {
            
        };
        
        
        PlusTab operator+(const PlusTab &P2)
        {
            PlusTab ObjN(szRow, szCol);
            for(int i=0; i<szRow; i++)
            {
                for(int j=0; j<szCol; j++)
                {
                    
                }
            }
            return(ObjN);
            
        };
};

#endif	/* PLUSTAB_H */