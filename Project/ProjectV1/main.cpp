/* 
 * File:   main.cpp
 * Author: Jose
 *
 * Created on October 24, 2016, 1:24 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

#include "Link.h"
#include "board.h"

using namespace std;

/*
 * 
 */
//name of link list
void start(Link *);
void makeLnk(Link *, string, string);
void rules();
void makeBrd();


int main(int argc, char** argv) 
{
    //display the rules
    rules();
    //link list for player information, score, name
    Link *list = new Link;
    //start the game, initiate with link list
    start(list);
    //create the boards
    board p1; 
    board p2;
    board p1copy;
    board p2copy;
    
    
    return 0;
}

//functions
void start(Link *list)
{
    string nameP1; //name of player 1
    string nameP2; //name of player 2
    cout<<"Enter Name of Player 1"<<endl;
    //enter name of player 1
    cin>>nameP1;
    cout<<"Enter Name of Player 2"<<endl;
    //enter name of player 2
    cin>>nameP2;
    cout<<"Creating List for players"<<endl;
    //create link list with given info
    makeLnk(list, nameP1, nameP2);
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
void makeLnk(Link * front, string name1, string name2)
{
    //create new link
    Link *add = new Link;
    //set front name to name of player 1
    front->name = name1;
    //set score of player 1 to 0 
    front->score = 0;
    //iterate to next player
    front->next = add;
    //set player 2 link name = name 2
    add->name = name2;
    //set player 2 pointer to NULL to indicate end of player list
    add->next = NULL;
    //set score of player 2 node to 0
    add->score = 0;
}

