/* 
 * File:   shipps.h
 * Author: Jose Sanchez
 * Purpose: ship class
 * Created on June 4th 2016
 */

//define ship.h
#ifndef SHIPPS_H
#define SHIPPS_H

//System Libraries 
#include <iostream>
using namespace std;

//user libraries

//create class warShip
class warShip{
    protected:
        string sName; //name of ship
        int size;   //size of ship
        int xpos;   //x position of ship    
        int ypos;   //y position of ship
        int fxpos;  //final x position of ship
        int fypos;  //final y position of ship
        static int totShip; //keeps count of number of ships
    public:
        warShip();  //constructor
        void bShipC(int , int , int , int); //creates ships
        void setsNam(string n){sName=n;} //sets the name of the ship
        void setSize(int n){size=n;}        //sets the size of the ship
        virtual void info(){};      //for polymorphism 
        int getxpos() const {return xpos;}  //gets x position
        int getypos() const {return ypos;}  //gets y position
        int getfxpos() const {return fxpos;}    //gets final x position
        int getfypos() const {return fypos;}    //gets final y position
        int getSize() const {return size;}      //gets the size of the ship
        string getName() const {return sName;}  //gets the name of the ship
};
#endif /* SHIPPS_H */

