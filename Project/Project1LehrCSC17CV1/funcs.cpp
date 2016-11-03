/* 
 * File:  funcs.cpp
 * Author: Jose Sanchez
 * Purpose: hold main functions
 * Created on October 24, 2016, 2:37 PM
 */

//System Libraries 
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <fstream>

//user libraries
#include "board.h"
#include "plyrInfo.h"
#include "Link.h"
using namespace std;

//global constants

//add to end of the list
Link *addLst(Link *front, int scoreP, int turn)
{
    Link *temp=front,*next; //Declare pointers used to step through the list
    do{
        next=temp;          //Point to the current link with a swap
        temp=temp->next; //Point to the next link
    }while(temp!=NULL);     //Your done when you hit the end
    Link *last = next;  //Find the last link
    Link *add = new Link;        //Create the new link
    add->score = scoreP;            //Add the data
    add->turn = turn;           //keeps track of the turn
    add->next = NULL;         //Set the pointer to NULL
    last->next = add;         //Point to the new end of the list    
}

//
//
//print the list
void  prntLst(Link *front){
    Link *next=front;           //Create a pointer to the list
    do{
        //Print the contents of the link
        cout<<"On turn: "<< next->turn <<" Number of hits: "<<next->score<<endl; 
        next=next->next;     //Go to the next link in the list
    }while(next!=NULL);         //Loop until reaching the end
}

//crate link lists
void makeLnk(Link *list)
{
    list->turn = 0; //set turn to 0
    list->score =0; //set score to 0
    list->next = NULL; //set next to NULL
}

//get the rules of the game, reused code from last project
void rules(){
    fstream rules; //rules fstream
    string line;  //to read into 
    
    //open the file rules.txt for input
    rules.open("rules.txt", ios::in);
    
    //if failed to open  tell user failed to open
    if (rules.fail())
    {
        cout<<"rules.txt not found!"<<endl;
    }
    //else display contents of the .txt
    else{
        while(! rules.eof()){       //while !rules.eof())
            getline(rules, line); //call get line
            cout<<line<<endl;
        }
    }
    cout<<endl;
    //close rules file
    rules.close();
}

//this functions changes a character to an integer
int CtoInt(char y){
    //switch case for character y
    switch (y)
    {
        case 'A':return 1; //if 'A':return 1;
        case 'B':return 2; //IF   'B':return 2;
        case 'C':return 3; // if  'C':return 3;
        case 'D':return 4; //  if 'D':return 4;
        case 'E':return 5; //if   'E':return 5;
        case 'F':return 6; //if   'F':return 6;
        case 'G':return 7; //if   'G':return 7;
        case 'H':return 8; //if   'H':return 8;
        case 'I':return 9; //if   'I':return 9; 
        case 'J':return 10;//if   'J':return 10;
        default: { //default return 10
            cout<<"ERROR: Enter character A-J"<<endl;
            return 11;
        }
    }
}
//This function is used to make sure the user entered in an int 
int strTest(string x){
    //char test=x[0];
    char test=x[0];
    //switch case test
    switch (test)
    {
        case '1': //if '1'
            if(x[1]=='0') //if x[1]=='0'
            {
                return 10; //return 10
            }
            else
            {   //else 
                return 1; //return 10
            }
        case '2':return 2;  //if '2' return 2;
        case '3':return 3;  //if '3' return 3;
        case '4':return 4;  //if '4' return 4;
        case '5':return 5;  //if '5' return 5;       
        case '6':return 6;  //if '6' return 6;
        case '7':return 7;  //if '7' return 7;
        case '8':return 8;  //if '8' return 8;
        case '9':return 9;  //if '9' return 9;
        default: return 11; //default return 11
    }
}

//This function is used to get the coordinates of the users ships
void inputS(board &player, int i){
    int x=0; //x for input
    int y=0;  //y for y input
    string x1; //x1 for string input
    string xTwo; //xTwo for string input
    int x2=0;   //x2 int input
    int y2=0;   //y2 for conversion
    char Cypos; //character input for user
    bool reDo=false; //redo=false for repeat
    
    //do
    do{ //set redo to false
        reDo=false;
        //output player.getN(i), player.getSzs(i)
        cout<<"Enter "<<player.getN(i)<<" which is of size"
                " "<<player.getSzs(i)<<endl;
        //enter the initial y position
        do
        {   
            cout<<"enter the initial y position A-J"<<endl;
            cin>>Cypos; //enter Cypos
        } while(CtoInt(toupper(Cypos))==11); //while CtoInt(toupper(Cypos))==11
        
        //convert
        y=CtoInt(toupper(Cypos));
        //do while loop
        do
        {   //enter string x1
            cout<<"enter the initial x position 1-10"<<endl;
            cin>>x1;
            x=strTest(x1); //convert string to an int
            try //try 
            {   //if x>10||x<1
                if(x>10||x<1)
                {   //thro string 
                    string error1="ERROR:Please enter a value between 1 and 10";
                    throw error1;
                }
            }
            catch (string error1) //catch thrown string
            {   //output thrown string
                cout<<error1<<endl;
            }
        } //while  (x>10||x<1)
        while(x>10||x<1);
        
        //do while loop
        do
        {    
            cout<<"enter the final y position A-J"<<endl;
            cin>>Cypos; //enter Cypos
        } while(CtoInt(toupper(Cypos))==11);//while CtoInt(toupper(Cypos))==11
        
        //do while loop
        do{ //enter xTwo
            cout<<"enter the final x position 1-10"<<endl;
            cin>>xTwo;
            x2=strTest(xTwo); //convert string to int
            try //try 
            {   //if    x2>10||x2<1
                if(x2>10||x2<1)
                {   //throw string
                    string error1="ERROR:Please enter a value between 1 and 10";
                    throw error1;
                }
            } //catch string
            catch (string error1)
            {   //output string
                cout<<error1<<endl;
            }
        }while(x2>10||x2<1); //while    x2>10||x2<1
        
        //convert
        y2=CtoInt(toupper(Cypos));
        try //try
        {   //reDo=player.testCor(i, x, y, x2, y2);
            reDo=player.testCor(i, x, y, x2, y2);
        }
        catch(board::invalid)
        {   //catch board::invalid
            cout<<endl;
            cout<<"Invalid Coordinates were entered"<<endl;
            cout<<"Re-Enter Values with the with correct size"<<endl;
            cout<<endl;
            player.display(); //player.displau
        }
    }while(!reDo); //while !reDo
    
    //create ship with initial x and pos positions
    player.makeShp(i, x, y, x2, y2);
    player.shipOn(i);
    player.disCoor(i);
    player.fillrest(i);
}

//enter in values for the guesses
void enterG(board& player, board& pCopy,  info pInfo[], int i){
    int xVal=0; //xValue
    int y1=0;   //yValue
    string x1;  //string input for x
    char yVal;  //character input for y
    char guess; //guess to see if the user wishes to continue
    
    //do while guess=='N'
    cout<<"Displaying "<<pInfo[i].names<<" HIT/MISS board"<<endl;
    pCopy.display();
    do{
        cout<<"Enter guess "<<pInfo[i].names<<endl;
        cout<<"Enter guess for the Y Position (A-J)"<<endl;
        do
        {   
            cout<<"enter the initial y position A-J"<<endl;
            cin>>yVal;
        } while(CtoInt(toupper(yVal))==11);
        //enter guess for the x value
        cout<<"Enter guess for the X Position (1-10)"<<endl;
        do
        { //try to see if user entered value is valid 
            cin>>x1;
            xVal=strTest(x1);
            try
            {   //if x>10||x<1
                if(xVal>10||xVal<1)
                {   // throw string if true
                    string error1="ERROR:Please enter a value between 1 and 10";
                    throw error1;
                }
            } //catch string thrown 
            catch (string error1)
            {   //output string thrown 
                cout<<error1<<endl;
            } 
        }while(xVal<1||xVal>10); //do while user entered value is x>10 || x<1
        cout<<"Entry received: "<<xVal<<endl<<endl;
        //enter value for the y
        //set y value 
        y1=CtoInt(toupper(yVal));
        cout<<"Entry received: "<<yVal<<endl<<endl;
        cout<<"Coordinate received: Y value: "<<yVal<<" X Value: "<<xVal<<endl;
        cout<<"Are the coordinates entered correct?: Y/N"<<endl;
        cin>>guess;
    }while(toupper(guess)!='Y');
    player.getGess(xVal, y1);
}
//deletes linked lists
void  destLst(Link *front){
    do{
       Link *temp=front->next;   //Point to the next link in the list
       delete front;                //Delete the front of the list
       front=temp;                  //Swap the front
    }while(front!=NULL);
}