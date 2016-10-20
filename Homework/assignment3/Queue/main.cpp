//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 21st, 2016 8:40 PM
 * Purpose:  Linked List Version 1 - Procedures with ADT
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here
#include "Link.h"

//Global Constants Only, No Global Variables

//Function Prototypes Here
Link *fillLst(int);         //Fill a linked list, count backwards
void  prntLst(Link *);      //Print each data element in the list
void  destLst(Link *);      //Destroy the list/deallocate
int    cntLst(Link *);      //How many elements are in the list
Link * endLst(Link *);      //Find the end of the list
Link * bfrEnd(Link *);      //Find address of node before last
Link *  push(Link *,int);  //Add data at the end of the list
Link * popOff(Link *);      //popOff top value
int    top(Link *);         //returns top value



//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare a pointer to the linked list and data to test in link creation
    Link *lnkList;
    int numList=8,valAdd=42,valFnd1=5,valFnd2=11;
    
    //sorting link list
    cout<<"STACK IN FORM OF LINKED LIST"<<endl;
    
    //Fill the linked list
    lnkList=fillLst(numList);
    
    
    //size
    cout<<"Size of the stack"<<endl;
    cout<<cntLst(lnkList)<<endl;
    //Add a value to the end of the list
    cout<<"Push on top of q value: "<<valAdd<<endl;
    lnkList = push(lnkList,valAdd);
    //Print the entire list
    prntLst(lnkList);
    
    
    //popOff
    cout<<"Pop off top of stack "<<endl;
    lnkList = popOff(lnkList); 
    prntLst(lnkList);
    
    
    //top
    cout<<"Top value on stack"<<endl;
    cout<<top(lnkList);
    

    //Deallocate memory for the Linked List
    destLst(lnkList);
    
    //Exit
    return 0;
}

int top(Link *front)
{
    return front->data;
}
//popOff last value
Link * popOff(Link *front)
{
    Link *temp = front->linkPtr;
    front = NULL;
    return temp;
}
//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//finds address of 
Link  *bfrEnd(Link *front){
    Link *temp=front,*next; //Declare pointers used to step through the list
    while(temp->linkPtr!=NULL)
    {   
        next=temp;          //Point to the current link with a swap
        temp=temp->linkPtr; //Point to the next link
    }
    return next;
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Create a linked list and fill with data
//Input  -> n      The number of elements in the list to create
//Output -> front  The address to the front of the allocated list.
Link *fillLst(int n){
    //Think of this part as the constructor
    Link *front=new Link;//Allocate a link at the front of the list
    front->data=n;       //Initialize with data
    front->linkPtr=NULL; //At the moment not pointing it to anything
    Link *next=front;    //Create a pointer to progress through the list

    //Fill the rest of the list with decreasing data down to 1
    n--;
    do{
       Link *temp=new Link; //Allocate a new link
       temp->data=n;        //Fill with data
       temp->linkPtr=NULL;  //Place at the end
       next->linkPtr=temp;  //Hook the new link to the end of the list
       next=temp;           //Move the pointer to the end
    }while(--n>0);          //Continue till you count down to Zero
    //Exit by return the original link pointer
    return front;           //Return the front pointer to the list
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Print the entire contents of the linked list
//Input -> front  The address to the front of the allocated list.
//Output-> Display the entire linked list.
void  prntLst(Link *front){
    Link *next=front;           //Create a pointer to the list
    cout<<endl<<"The Beginning of the List"<<endl;
    do{
        cout<<next->data<<endl; //Print the contents of the link
        next=next->linkPtr;     //Go to the next link in the list
    }while(next!=NULL);         //Loop until reaching the end
    cout<<"The End of the List"<<endl<<endl;
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Deallocate the entire list from the front to the end.
//Input -> front  The address to the front of the allocated list.
//Output-> Deallocate and return a NULL for the linked list pointer.
void  destLst(Link *front){
    do{
       Link *temp=front->linkPtr;   //Point to the next link in the list
       delete front;                //Delete the front of the list
       front=temp;                  //Swap the front
    }while(front!=NULL);
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Find the address of the last link in the list
//Input -> front  The address to the front of the allocated list.
//Output-> The address of the last link in the list
Link  *endLst(Link *front){
    Link *temp=front,*next; //Declare pointers used to step through the list
    do{
        next=temp;          //Point to the current link with a swap
        temp=temp->linkPtr; //Point to the next link
    }while(temp!=NULL);     //Your done when you hit the end
    return next;
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Add a link and data to the end of the list
//Input -> front  The address to the front of the allocated list.
//         data   Data to embed at the last link in the list
Link * push(Link *front,int data){
    Link *top = front;
    Link *newTop = new Link;
    newTop->data = data;
    newTop->linkPtr = top;
    return newTop;
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Find the number of links in the list
//Input -> front  The address to the front of the allocated list.
//Output-> The number of links in the list
int   cntLst(Link *front){
    int n=0;            //Initialize the counter
    Link *temp=front;   //Set the cursor to the front
    do{
        n++;            //Increment the counter
        temp=temp->linkPtr;//Move to the next link
    }while(temp!=NULL); //Loop until the end is reached
    return n;           //Return the counter value
}
