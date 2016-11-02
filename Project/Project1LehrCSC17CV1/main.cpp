/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Purpose: Battleship
 * Created on October 30 2016
 */

//System Libraries 
#include <iostream>
#include <fstream>
#include <map>
#include <set>
using namespace std;

//user libraries
#include "board.h"
#include "Link.h"

//global constants

//Function Prototypes
void destLst(Link *); //destroys linked list
void inputS(board&, int); //input
char checkC(board, int, int, int, int, int); //check for hit
void rules(); //display rules
void enterG(board&, board&, info[], int i); //enter the game
void names(info[]);  //names 
void makeLnk(Link *); //create the link list
void prntLst(Link *); //print the link list
Link * addLst(Link *, int, int); //create new link add to last
//Execution begins here
int main(int argc, char** argv) {
    Link *listP1 = new Link; //create link list to hold statistical data for p1
    Link *listP2 = new Link; //crate link list to hold statistical date for p2
    int turn = 0; //turn number
    int hit1 = 0; //player 1counter
    int hit2 = 0; //player 2 hit counter
    map<string, float> bets; //map for bets. hold name of gambler, better
    set<float> pot;     //set to hold the total win amount for player
    float betAmnt = 0; //the amount to be gambled 
    string betName; //name of gamblers
    float totalBet = 0; //the total amount on the game
    
    char bet; //choice for more betting
   // string names; //names of potential betters
   // float amount; //amount being bet
    

    bool win=false; //win for player 1
    bool win2=false;    //win for player 2
    bool winner=true;   //winner=true
    info *players = new info[NUMPLAY];  //dynamic array of structs
    fstream file;   //file 
    fstream rFile;  //rFile
    
    makeLnk(listP1); //create link list for turn 1
    makeLnk(listP2); //create link list for turn 2
    
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
    
    //call function names
    names(players);
    
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
    cout<<"The pot total its: "<<*itr<<endl;

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
            //if 
            addLst(listP1, ++hit1, turn);   
        }
        else
        {
            addLst(listP1, hit1, turn);  
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
            //if hit, addd to link and hit count
            addLst(listP2, ++hit2, turn);   
        }
        else
        {
            //if miss, do not add to hit count, add to link
            addLst(listP2, hit2, turn);  
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
    prntLst(listP1);
    cout<<"Press Enter to view next player turn by turn stats"<<endl;
    cin.ignore();
    cout<<"Turn by turn statistics for Player: "<<players[1].names<<endl;
    prntLst(listP2);
    cout<<"Press enter to see general statistics"<<endl;
    cin.ignore();
    
    //if player 1 won
    if(win!=true)
    {   //output hits, misses, guesses, payout, and name
        cout<<"Congrats to the winner "<<players[0].names<<endl;
        cout<<"Total Winnings for bet on :"
                " "<<players[0].names<<": "<<*itr<<endl;
        cout<<"Displaying statistics"<<endl;
        cout<<"Total number of guesses: "<<player1.getGss()<<endl;
    }
    //if player 2 won
    if(win2!=true)
    {   //output hits, misses, guesses, payout, and name
        cout<<"Congrats to the winner "<<players[1].names<<endl;
        cout<<"Total Winnings for bet on :"
                " "<<players[1].names<<": "<<*itr<<endl;
        cout<<"Displaying statistics"<<endl;
        cout<<"Total number of guesses: "<<player2.getGss()<<endl;
    }
    
    //loop to fill in structured data to send to file;
    for(int i=0; i<SIZE; i++)
    { //loop 10 times
        for(int j=0; j<SIZE; j++)
        {   //loop 10 times
            players[0].arr[i][j]=player1.getGrd(i, j);//get the coordinates(i,j)
        }
    }
    
    //loop to fill in structured data to send to file;
    for(int i=0; i<SIZE; i++)
    {   //loop 10 times
        for(int j=0; j<SIZE; j++)
        {   //loop 10 times
            players[1].arr[i][j]=player2.getGrd(i, j);//get the coordinates(i,j)
        }
    }

    //write object contents to a file "Stats.dat" as binary information
    file.open("Stats.dat", ios::out | ios::binary);
    file.write(reinterpret_cast<char *>(&players), sizeof(players));
    file.close();  
    
    //open the "Stats.dat" binary file and read it into a structure
    rFile.open("Stats.dat", ios::in | ios::out | ios::binary);
    rFile.read(reinterpret_cast<char *>(&players), sizeof(players));
    //display contents of structure for loop p<NUMPLAY
    cout<<players[0].names<<"'s Board"<<endl; //output readIn[p].name
    //loop to display
    cout<<"    1   2   3   4   5   6   7   8   9   10"<<endl;
    //loop for 10 times
    for(int i=1; i<SIZE; i++)
    {   //output static cast of p
        cout<<static_cast<char>('a'+i);
        //loop 10 time for the columns
        for(int j=1; j<SIZE; j++)
        {   //output array[i][j]
            cout<<" | "<<players[0].arr[i][j];
        }  
        cout<<endl;
    } 
    
    //write object contents to a file "Stats.dat" as binary information
    file.open("Stats2.dat", ios::out | ios::binary);
    file.write(reinterpret_cast<char *>(&player2), sizeof(player2));
    file.close();  
    
    //open the "Stats2.dat" binary file and read it into a structure
    rFile.open("Stats2.dat", ios::in | ios::out | ios::binary);
    rFile.read(reinterpret_cast<char *>(&players), sizeof(players));
    //display contents of structure for loop p<NUMPLAY
    cout<<players[1].names<<"'s Board"<<endl; //output readIn[p].name
    cout<<"    1   2   3   4   5   6   7   8   9   10"<<endl;
    //loop for 10 times
    for(int i=1; i<SIZE; i++)
    {   //output static cast of p
        cout<<static_cast<char>('a'+i);
        //loop 10 time for the columns
        for(int j=1; j<SIZE; j++)
        {   //output array[i][j]
            cout<<" | "<<players[1].arr[i][j];
        }  
        cout<<endl;
    } 

    //delete linked lists
    destLst(listP1);
    destLst(listP2);
    //delete dynamically created array
    delete [] players;
    
    return 0;
}