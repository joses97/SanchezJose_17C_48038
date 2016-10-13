// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

struct Link{
    int data;		//Any integer data, to be changed any class with templates later
    Link *linkPtr;  //Self Reference which when utilized forms a linked list
};


class SimpleVector
{
private:
   Link *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector(){};
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }
   
   //push back
   void pushback(int num);
   
   //pop off
   void popoff();
   
   
   //display the array
   void display();
};

        
//popoff
void SimpleVector::popoff()
{
    cout<<"Popping off last";
    Link *temp=aptr,*next; //Declare pointers used to step through the list
    while(temp->linkPtr!=NULL)
    {     //Your done when you hit the end
        next=temp;          //Point to the current link with a swap
        temp=temp->linkPtr; //Point to the next link
    }
    next->linkPtr = NULL;
}

//pushback
//copy paste from part 2
void SimpleVector::pushback(int num)
{
    cout<<"Pushing back "<<num;
    Link *temp=aptr,*next; //Declare pointers used to step through the list
    do{
        next=temp;          //Point to the current link with a swap
        temp=temp->linkPtr; //Point to the next link
    }while(temp!=NULL);     //Your done when you hit the end
    
    
    Link *last=next;  //Find the last link
    Link *add=new Link;        //Create the new link
    add->data=num;            //Add the data
    add->linkPtr=NULL;         //Set the pointer to NULL
    last->linkPtr=add;         //Point to the new end of the list   
}

//display 
void SimpleVector::display()
{   //Lehrs code
    Link *next=aptr;           //Create a pointer to the list
    cout<<endl<<"The Beginning of the List"<<endl;
    do{
        cout<<next->data<<endl; //Print the contents of the link
        next=next->linkPtr;     //Go to the next link in the list
    }while(next!=NULL);         //Loop until reaching the end
    cout<<"The End of the List"<<endl<<endl;
}

//constructor
SimpleVector::SimpleVector(int size)
{
    arraySize=size;
    aptr->data = 0;
    Link *temp = aptr;
    
    for(int i=1; i<size; i++)
    {
        Link * next = new Link;
        next->data = i;
        temp->linkPtr = next; 
        temp=next;
    }
    temp->linkPtr=NULL;
    
}

//push back
#endif



