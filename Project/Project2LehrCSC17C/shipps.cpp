/* 
 * File:   shipps.cpp
 * Author: Jose Sanchez
 * Purpose: hold functions for class
 * Created on December 13 2016
 */

//System Libraries 

//User libraries
#include "shipps.h"

//global constants

//shipps.h functions
//******************************************************************************
//initialize the total amount of ships to 0
int warShip::totShip=0;
//Constructor initialize all protected members to 0
warShip::warShip(){
    xpos=0; //xpos=0
    ypos=0; //ypos=0
    fxpos=0; //fxpos=0
    fypos=0; //fypos=0
    totShip++; //totShip++
}
// assigns values to the protected member functions
void warShip::bShipC(int x, int y , int x2,  int y2){
    xpos=x;     //set xpos=x
    ypos=y;     //set ypos=y
    fxpos=x2;   //set fxpos=x2
    fypos=y2;   //set fypos=y2
}