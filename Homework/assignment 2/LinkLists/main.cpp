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
Link * endLst(Link *);      //Find the end of the list
void   addLst(Link *,int);  //Add data at the end of the list
int   findLst(Link *,int);  //Determine what link contains the data
Link * fndLst(Link *,int);  //Determine address of link that contains the data
int    cntLst(Link *);      //How many elements are in the list
Link * addStrt(Link *, int);    //Adds a link to the beginning
Link * addAftr(Link *, int, int);    //adds value int after int
Link * addBefr(Link *, int, int);   //adds value int before int
Link * fndBefr(Link *, int);          //find link pointer before given value
Link * delVal(Link *, int);     //deletes link at that hold given value;

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare a pointer to the linked list and data to test in link creation
    Link *lnkList;
    int numList=8,valAdd=42,valFnd1=5,valFnd2=11;
    
    //Fill the linked list
    lnkList=fillLst(numList);
    
    
    //Print the entire list
    prntLst(lnkList);
    
    //Add a value to the end of the list
    addLst(lnkList,valAdd);
    
    //Print the entire list after adding to it
    prntLst(lnkList);
    
    //Find some values in the List
    cout<<valFnd1<<" is found at link    "<<findLst(lnkList,valFnd1)<<endl;
    cout<<valFnd1<<" is from the address where data = "
            <<fndLst(lnkList,valFnd1)->data<<endl;
    cout<<valFnd2<<" is found at link   "<<findLst(lnkList,valFnd2)<<endl;
    cout<<"The number of elements in the list = "<<cntLst(lnkList)<<endl;
    
    //add 2
    cout<<endl<<endl<<"ADDING TO THE FRONT VALUE 2"<<endl;
    lnkList = addStrt(lnkList, 2);
    
    //print list
    cout<<"Print the list with 2 added at the beginning"<<endl;
    prntLst(lnkList);
    
    //add after a number given
    cout<<endl<<endl<<"Add 99 after value 5 in list"<<endl;
    lnkList = addAftr(lnkList, 5, 99);
    prntLst(lnkList);
    
    //add before a number given
    //adds the number 23 before the number 6
    lnkList = addBefr(lnkList, 6, 23);
    
    //display
    cout<<"Adding value 23 before 6"<<endl;
    prntLst(lnkList);
    
    //delete value 4
    cout<<"Deleting link which contains data=4"<<endl;
    lnkList = delVal(lnkList, 4);
    prntLst(lnkList);
    
    
    //Deallocate memory for the Linked List
    destLst(lnkList);
    
    //Exit
    return 0;
}

Link *delVal(Link *front,  int value)
{
    Link *temp1 = new Link; //create new link
    Link *temp2 = new Link; //create new link
    
    temp1 = fndLst(front, value); //set  temp1 to link for given delete value
    temp2 = fndBefr(front, value); //set temp2 to link before delete value
    
    temp2->linkPtr=temp1->linkPtr; //set temp2's lnkptr to temp1's lnkptr
    temp1=NULL; //set temp1 = NULL

    return front;
    
}

//adds to the beginning of the node
Link *addStrt(Link *front, int data)
{
    Link *temp = new Link;
    temp->linkPtr = front;
    temp->data = data;
    return temp; 
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
void   addLst(Link *front,int data){
    Link *last=endLst(front);  //Find the last link
    Link *add=new Link;        //Create the new link
    add->data=data;            //Add the data
    add->linkPtr=NULL;         //Set the pointer to NULL
    last->linkPtr=add;         //Point to the new end of the list
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Find the number of the link that matches the data
//Input -> front  The address to the front of the allocated list.
//Output-> The Link number from the front where the data is found
int   findLst(Link *front,int value){
    int n=0;                //Initialize the counter
    Link *temp=front;       //Prepare to traverse the Linked list
    do{
        n++;                //Increment the counter
        if(temp->data==value)return n;//Return where the data is found
        temp=temp->linkPtr; //Move to the next link
    }while(temp!=NULL);     //End when reaching the end of the linked list
    return 0;               //Not found then return a 0;
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Find the address of the link that matches the data
//Input -> front  The address to the front of the allocated list.
//Output-> The Link address from the front where the data is found
Link  *fndLst(Link *front, int value){
    Link *temp=front;       //Set the cursor to move through the list
    do{
        if(temp->data==value)return temp;  //Address of data match
        temp=temp->linkPtr;                //Next link in the list
    }while(temp!=NULL);                    //End of the list
    return NULL;                           //Not found
}

//find value before
Link *fndBefr(Link *front, int value)
{
    Link *temp = front;
    do
    {
        if(temp->linkPtr->data==value) return temp;
        temp = temp->linkPtr;
    }while(temp!=NULL);
    return NULL;
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

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//adds after a value
Link *addAftr(Link *front, int val, int addVal)
{
    Link *add = new Link; //create link to add
    add->data = addVal;       //set addVal
    Link *temp = new Link; //create new temp, find location of val
    temp = fndLst(front, val);  //set temp pointer = location of found value
    add->linkPtr = temp->linkPtr; //make it so temp and add point to same thing
    temp->linkPtr = add;    //point temp to add;

    return front;
}

//
//
//adds before a value
Link * addBefr(Link *front, int val, int addVal)
{
    Link *add = new Link; //create new link add
    add->data = addVal;     //set its data = to addVal
    Link *temp = new Link;  //create new link 
    Link *temp2 = new Link; //create second new link for copying
    temp = fndLst(front, val); //set temp = point in chain where value is found
    add->linkPtr = temp;    //set the added link's ptr point to temp
    
    //set temp2 list = point before the value given
    temp2 = fndBefr(front,val);

    //point the before to the added link
    temp2->linkPtr = add;
    
    //return the front
    return front;
    
}