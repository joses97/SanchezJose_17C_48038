// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
private:
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   int eleNum;     //number of elements
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
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }
  
   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
   
   //push back
   T pushback(int num);
   
   //pop off
   T popoff();
   
   //display the array
   T display();
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

//popoff
template <class T>
T SimpleVector<T>::popoff()
{
    eleNum=eleNum-1;
    int size=arraySize;
    int size2=size/2;
    T *newArr;

    //popoff
    if(eleNum>0)
    {
        aptr[eleNum]=0;
    
        //test to determine if a new smaller array should be created.
        if(eleNum<size2)
        {
            //create new array of half the size + 1
            newArr = new T[size2];

            //initialize new values of array to 0
            for(int i=0; i<size2; i++)
            {
                newArr[i]=0;
            }

            //copy contents of array
            for(int i=0; i<eleNum; i++)
            {
                newArr[i]=aptr[i];
            }

            //delete 
            delete aptr;

            //recreate the aptr array with new size

            aptr = new T[size2];

            //reassign
            for(int i=0; i<size2; i++)
            {
                aptr[i] = 0;
            }
            for(int i=0; i<size2; i++)
            {
                aptr[i] = newArr[i];
            }

            aptr[eleNum]=0;
            arraySize=size2;
        }
    }
     

    
    
}

//pushback
template <class T>
T SimpleVector<T>::pushback(int num)
{
    eleNum+=1;
    int size=arraySize;
    T *newArr;
    
    //test to determine if expansion is needed
    if(eleNum>=size)
    {
        //double size if number of elements is greater than size of current array
        size=size*2;
        //create new array of double the size of previous array
        newArr = new T[size];
        
        //set new array = 0
        for(int i=0; i<size; i++)
        {
            newArr[i]=0;
        }
        
        //loop to copy contents
        for(int i=0; i<arraySize; i++)
        {
            newArr[i]=aptr[i];
        }
        //assign value of newArr at the current number of total elements to num
        newArr[eleNum-1]=num;
        //delete pointer
        delete aptr;
        //dynamically recreate array with double the size
        aptr = new T[size];
        //copy back
        for(int i=0; i<size; i++)
        {
            *(aptr+i) = newArr[i];
        }
        //delete array created
        delete newArr;
        
        //apply new size of array
        arraySize=size;
    }
    
    if(eleNum<size)
    {
        aptr[eleNum-1]=num;
    }    
}

//display the array
template <class T>
T SimpleVector<T>::display()
{
    for(int i=0; i<arraySize; i++)
    {
        cout<<aptr[i];
    }
    cout<<endl<<endl;
}

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   eleNum=s;
   arraySize = s;
   // Allocate memory for the array.
   try
   {
      aptr = new T [s];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//pushback 
//template <class T>


#endif



