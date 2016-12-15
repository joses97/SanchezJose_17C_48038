/* 
 * File:   board.cpp
 * Author: Jose Sanchez
 * Purpose: hold functions
 * Created on October 24, 2016, 2:37 PM
 */

//System Libraries 
#include <iostream>
#include <cmath>
#include <string>

//User Libraries
#include "board.h"
using namespace std;

//Board.cpp functions held here
//******************************************************************************
//initialize static variable to 0
int board::guesses=0;
//******************************************************************************
//Set static variable of array of 5 to the values of names of ships
int board::sizes[NUMSHIP]={5, 4, 3, 3, 2};
//******************************************************************************
//Set static variable of array of 5 to the values of names of ships
string board::names[NUMSHIP]={"Carrier", "Battleship", "Cruiser", "Submarine",
    "Destroyer"};
//******************************************************************************
//Defaulted Constructor For creating a board
board::board(){
    //create 5 ships per board, dynamically create 5 ships of class warShip
    ships = new warShip[NUMSHIP];
    //for loop to create the 10x10 board
    for(int i=0; i<SIZE; i++) //loop 10 times for row
    { 
        for(int j=0; j<SIZE; j++) //loop 10 times for column
        {
            array[i][j]='-'; //set the private member to - for the grid
        }
    }
    //initial values to 0
    hits=0;
    misses=0;
    xGuess=0;
    yGuess=0;
}
//******************************************************************************
//defaulted constructor
board::~board(){
    //delete the dynamically created array of ships
    delete [] ships;
}
//******************************************************************************
//gets access to the board positions
char board::getGrd(int x, int y){
    return array[x-1][y-1];
}
//******************************************************************************
//gets access to the board positions
bool board::chekWin(){
    if(hits>=17) {
        return true;
    }
    else {
        return false;
    }
}
//******************************************************************************
//gets access to the board positions
bool board::check(int x, int y, board& copy){
    //check to see if the position entered contains a 'X' 
    if(array[x-1][y-1]=='X'){  
        //if    copy.array[x-1][y-1]=='X'
        if(copy.array[x-1][y-1]=='X')
        {   //output
            cout<<"This space has already been hit!"<<endl;
        }
        else 
        {   
            cout<<"Its a hit!"<<endl;
            copy.array[x-1][y-1]='X'; //place a 'X' for a hit on the copy
            hits++; //adds one to the hits of the user
            guesses++;  //add one to guesses
            cout<<"Number of hits   "<<hits<<endl; //output hits
            return true;
        }
        
    }
    //if not
    else if(array[x-1][y-1]=='-')
    {
        cout<<"Its a miss!"<<endl;
        copy.array[x-1][y-1]='O'; //place a 'O' for a miss on the copy
        misses++; //adds one to the misses;
        guesses++; //add one to guesses
        cout<<"Number of misses   "<<misses<<endl; //output misses
        return false;
    }
}
//******************************************************************************
//assigns values to the guess for the player 
void board::getGess(int x, int y){
    xGuess=x;   //assigns value to the xGuess private member
    yGuess=y;   //assigns value to the yGuess private member
}
//******************************************************************************
//Test to see if user entered values are valid entries
bool board::testCor(int i, int xOne, int yOne, int xTwo, int yTwo){
    bool test1=false;   //to test if x is a constant
    bool test2=false;   //to test if y is a constant
    //set the size to the size of the ship, for testing users entered size
    int size=ships[i].getSize();
    
    //test to see if x is a constant
    if(abs(xOne-xTwo)==0)
    {
        test1=true; //if true set test1 to true, shows x is constant
    }
    
    //test to see if y is a constant
    if(abs(yOne-yTwo)==0)
    {
        test2=true; //if true set test2 to true, shows y is a constant
    }
    
    //test for x and y constance
    if(test1&&test2)
    {
        throw invalid();//if both x and y are constant return false, bad input
        return false;   //return false for bad input
    }

    // if test 1 was the constant test for the difference in y coordinates
    else if(test1)
    {
        if(abs(yOne-yTwo-1)==size)
        { //if difference is equal to size
            return true;    //return true for good input
        }
        else
        {   //else
            throw invalid(); //throw invalid for bad input
            return false;   //return false for a bad input
        }   
    }
    //if test 2 was the constant test for the difference in x coordinates
    else if(test2)
    {
        if(abs(xOne-xTwo-1)==size) //if difference in x was = to size
        { 
            return true;    //return true for good input
        }   
        else
        {
            throw invalid(); //throw invalid for bad input
            return false; //return false for a bad input
        }
    }
    //if for some reason all tests failed, 
    throw invalid();    //throw invalid
    return false;       //return false
}

//******************************************************************************
//set the size of each ship created
void board::setSize(){
    //loop 5 time to set the size of the ships
    for(int i=0; i<NUMSHIP; i++)
    {
        ships[i].setSize(sizes[i]);
    }
}
//******************************************************************************
//set the names of each ship created
void board::setSNms(){
    //loop 5 times to assign a name to the object
    for(int i=0; i<NUMSHIP; i++)
    {
        ships[i].setsNam(names[i]);
    }
}
//******************************************************************************
//get the name of the ship requested
string board::getN(int i){ //returns the name of the ship requested
    return ships[i].getName();
}
//******************************************************************************
//get the size of the ship requested
int board::getSzs(int i){ //returns the name of the ship requested
    return ships[i].getSize();
}
//******************************************************************************
//display the coordinates of the ship requested
void board::disCoor(int i){
    //Displays the coordinates of the ship at i 
    //output ships[i].getxpos(), ships[i].getypos()
    cout<<ships[i].getName()<<" initial position is located at: "
            ""<<ships[i].getxpos()<<" and "<<ships[i].getypos()<<endl;
    //output the final x and y position of the ship
    cout<<ships[i].getName()<<" final position is located at:"
            " "<<ships[i].getfxpos()<<" and "<<ships[i].getfypos()<<endl;
}
//******************************************************************************
//assigns one boards 2d array to the other
void board::operator =(const board& right){
    //= operator copies to board of one board object to another
        for(int i=0; i<SIZE; i++)
        { //loop 10 times for the row fill in
            for(int j=0; j<SIZE; j++)
            { //loop 10 times for the column fill in
                array[i][j]=right.array[i][j]; //array[i][j]=right.array[i][j];
            }
        }
}
//******************************************************************************
//makes the ship with the requested parameters 
void board::makeShp(int i, int a, int b, int c, int d){
    //fill in values for the  initial x and y position
    //c and d are the final x and y position
    ships[i].bShipC(a, b, c, d);
}
//******************************************************************************
//places the ship initial and final positions on the grid
void board::shipOn(int i){
    //assign the given ship initial coordinates to the array(board) 'X'
    array[ships[i].getypos()-1][ships[i].getxpos()-1]='X';
    //assign the final given ship coordinates to the array(board) to 'X'
    array[ships[i].getfypos()-1][ships[i].getfxpos()-1]='X';
}
//******************************************************************************
//displays the board 
void board::display(){
    //character to initiate the loop
    char p='A';
    //1-10 for the board
    cout<<"    1   2   3   4   5   6   7   8   9   10"<<endl;
    //loop for 10 times
    for(int i=0; i<SIZE; i++)
    {   //output static cast of p
        cout<<static_cast<char>(p+i);
        //loop 10 time for the columns
        for(int j=0; j<SIZE; j++)
        {   //output array[i][j]
            cout<<" | "<<array[i][j];
        }  
        cout<<endl;
    }      
}
//******************************************************************************
//fills in the positions from  the initial position selected to the initial
void board::fillrest(int n){
    //fills in from the initial ship position to the final position for x
    for(int i=ships[n].getxpos(); i<ships[n].getfxpos(); i++)
    {
        array[ships[n].getypos()-1][i]='X'; //array[ships[n].getypos()-1][i]='X'
    }
    

    ////fills in from the initial ship position to the final position for y
    for(int i=ships[n].getypos(); i<ships[n].getfypos(); i++)
    {
        array[i][ships[n].getxpos()-1]='X'; //array[i][ships[n].getxpos()-1]='X'
    }       
}
//******************************************************************************
board board::operator +(const board &){
    
}
//******************************************************************************
//adds one to the total amount of guesses
board& board::operator++(){
    guesses+=0;
    return *this;
}
//******************************************************************************
//adds one to the total amount of guess, static int 
board board::operator++(int){
    board temp = *this;
    ++*this;
    return temp;
}
