/* 
 * Author: Dr. Mark E. Lehr
 * Created on September 21st, 2016 8:40 Pm
 * Purpose:  Structure ADT for the Link
 */

#ifndef LINK_H
#define LINK_H

//Composition of a Link
struct Link{
    int data;		//Any integer data, to be changed any class with templates later
    Link *next;  //points to the next node in line
    Link *prev;     //points the previous node in line
};


#endif /* LINK_H */