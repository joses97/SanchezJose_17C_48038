/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Purpose: Battleship
 * Created on December 13 2016
 */

//System Libraries 
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

//user libraries
#include "board.h"
#include "binaryTree.h"

//global constants

//Function Prototypes
void inputS(board&, int); //input
char checkC(board, int, int, int, int, int); //check for hit
void rules(); //display rules
void enterG(board&, board&, info[], int i); //enter the game
unsigned int RSHash(const string& );
void display(Node *);
//Execution begins here
int main(int argc, char** argv) {      
    
    tree usr1; //tree for stats user 1
    tree usr2;  //tree for stats user 2
    int turn = 0; //turn number
    int hit1 = 0; //player 1counter
    int hit2 = 0; //player 2 hit counter
    map<string, float> bets; //map for bets. hold name of gambler, better
    set<float> pot;     //set to hold the total win amount for player
    float betAmnt = 0; //the amount to be gambled 
    string betName; //name of gamblers
    int hKey;
    string key;
    float totalBet = 0; //the total amount on the game
    char bet; //choice for more betting
    bool win=false; //win for player 1
    bool win2=false;    //win for player 2
    bool winner=true;   //winner=true
    info *players = new info[NUMPLAY];  //dynamic array of structs
    
    //make 4 boards
    board player1;
    board player2;
    board copy1;
    board copy2;
    
    //display the rules of the game
    rules();
    
    //set the names of the ships to the ships created
    player1.setSNms();
    player1.setSize(); //set the size of the ships to the ships created
    
    //set the names of the ships to the ships created
    player2.setSNms();
    player2.setSize(); //set the size of the ships to the ships created
    
    //copy board of one player to their respective copy boards
    copy1 = player1;
    copy2 = player2;
    
    //enter the info of the players
    for(int i=0; i<NUMPLAY; i++) //loop ten twice for each player
    {
        cout<<"Enter name of player "<<i+1<<" ";
        getline(cin, players[i].names);
    }
    
    //sort names using sort algorithm from stl library 
    vector<char> nameVec;
    for(int p=0; p<NUMPLAY; p++) //loop twice for players
    {   //loop for size of that players name
        for(int i=0; i<players[p].names.length() + 1; i++)
        {
            nameVec.push_back(players[p].names[i]);
        }
    }
    //sort the new vec
    sort(nameVec.begin(), nameVec.end());
    //show new vec
    cout<<"Here is the sort from low to high of player 1 and 2's name"<<endl;
    for(vector<char>::iterator i = nameVec.begin(); i != nameVec.end(); ++i)
    {
        cout<<*i;
    }
    cout<<endl<<endl;
    
    //enter the bets for each player
    for(int i=0; i<NUMPLAY; i++)
    {
        cout<<"Enter bet for "<<players[i].names<<endl;
        cin>>betAmnt;
        bets[players[i].names] = betAmnt;
    }
    
    //ask for other gamblers
    cout<<"Are others gambling on this game? Y/N"<<endl;
    cin>>bet;
    
    //loop for more players
    while(toupper(bet)=='Y')
    {
        cout<<"Enter Unique Name of Gambler ";
        cin>>betName;
        cout<<endl;
        cout<<"Enter Bet amount ";
        cin>>betAmnt;
        bets[betName] = betAmnt;
        cout<<"Any more gamblers betting on this game ? Y/N "<<endl;
        cin>>bet;
        cout<<endl;
    }
    
    //iterators for looping to find total amount gambled
    map<string, float>::iterator it = bets.begin();
    while(it != bets.end())
    {
        totalBet += it->second;
        ++it;
    }
    pot.insert(totalBet);
    
    //set iterator to pot.begin
    set<float>::iterator itr = pot.begin();
    cout<<"Create key to lock away bet with stakeholder"<<endl;
    cin>>key;
    hKey = RSHash(key);
    key = "";

    cout<<"Stakeholder has $"<<*itr<<endl;
    
    cout<<"This money was gambled across "<<bets.size()<<endl;

    //loop twice for each player
    for(int i=0; i<NUMSHIP; i++)
    {
        player1.display();  //displays the board
        inputS(player1, i); //gets the inputs of the player
        player1.display();  //displays the board
    }
    //creates space
    cout<<endl<<endl<<endl;
    
    //loop twice for each player
    for(int i=0; i<NUMSHIP; i++)
    {
        player2.display();  //displays the board
        inputS(player2, i); //gets the inputs of the player
        player2.display();  //displays the board
    }
    //creates space
    cout<<endl<<endl<<endl; 
    
    
    
    // begin the actual game
    do
    {
        ++turn; //increment the number of turns in total for the game
        //enter the gueeses for player 1
        enterG(player1, copy1, players, 0); //enter the  guesses
        //check to see if guess was a hit
        if(player2.check(player1.getYGss(), player1.getXGss(), copy1))
        {         
            usr1.insert(turn, ++hit1, player1.getXGss(), player1.getYGss());
        }
        else
        {
            usr1.insert(turn, hit1, player1.getXGss(), player1.getYGss());
        }
        copy1.display(); //show player 1 guess
        cin.ignore(); //ignore input
        cout<<"Press enter to continue to the next player"<<endl;
        cin.ignore(); //need to press enter 
        win = player1.chekWin(); //check for the win
        //if win==true
        if(win==true)
        {   //set winner to false
            winner=false;
        }
        
        //enter guesses for player 2
        enterG(player2, copy2, players, 1); //enter guesses for player 2
        //check for hit
        if(player1.check(player2.getYGss(), player2.getXGss(), copy2))
        {
            usr2.insert(turn, ++hit2, player2.getXGss(),  player2.getYGss());
            
        }
        else
        {  
            usr2.insert(turn, hit2, player2.getXGss(), player2.getYGss());
        }
        
        
        copy2.display();    //show player 2 guess board
        cin.ignore();   //ignore input
        cout<<"Press enter to continue to the next player"<<endl;
        cin.ignore(); //press enter to continue
        win2=player2.chekWin(); //check for the win 
        
        //if win2==true
        if(win2==true)
        { //set winner = false
            winner=false;
        }    
    }while(winner); //while winner
    
    cout<<"GAME OVER"<<endl;
    cout<<"Turn by turn statistics for Player: "<<players[0].names<<endl;
    display(usr1.rtrnNode());
    cout<<"Press Enter to view next player turn by turn stats"<<endl;
    cin.ignore();
    cout<<"Turn by turn statistics for Player: "<<players[1].names<<endl;
    display(usr2.rtrnNode());
    cout<<"Press enter to see general statistics"<<endl;
    cin.ignore();
    
    
    cout<<"Enter key to access pot from Stakeholder"<<endl;
    cin>>key;
    
    while(hKey != RSHash(key))
    {
        cout<<"Incorrect key entered, reenter Key"<<endl;
        cin>>key;
    }
    
    key = "";
    
    cout<<"Correct key entered "<<endl;
    
    
    //if player 1 won
    if(win!=true)
    {   //output hits, misses, guesses, payout, and name
        cout<<"Congrats to the winner "<<players[0].names<<endl;
        cout<<"Total Winnings for bet on :"
                " "<<players[0].names<<": "<<*itr<<endl;
        cout<<"Total number of guesses: "<<player1.getGss()<<endl;
    }
    //if player 2 won
    if(win2!=true)
    {   //output hits, misses, guesses, payout, and name
        cout<<"Congrats to the winner "<<players[1].names<<endl;
        cout<<"Total Winnings for bet on :"
                " "<<players[1].names<<": "<<*itr<<endl;
        cout<<"Total number of guesses: "<<player2.getGss()<<endl;
    }

    //delete dynamically created array
    delete [] players;
    
    return 0;
}