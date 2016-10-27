/* 
 * File:   Link.h
 * Author: Jose
 * Purpose Link List to keep track of data turn per turn
 * Created on October 24, 2016, 2:37 PM
 */

#ifndef LINK_H
#define LINK_H

//Link list struct
struct Link
{
    int turn; //number in line of the list
    int score; //hold the data for the node
    Link *next; //points to the next
    
};

#endif /* LINK_H */

