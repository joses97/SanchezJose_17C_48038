/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jose
 *
 * Created on September 21, 2016, 2:28 PM
 */

#include <iostream>
#include <cstdlib>
#include "SimpleVector.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    SimpleVector <int> obj1(10);
    SimpleVector <int> obj2(3); 
    
    obj2.display();


    for(int i=0; i<10; i++)
    {
        obj2.pushback(2);
        obj2.display();
  
    }  
    
    for(int i=0; i<30; i++)
    {
        obj2.popoff();
        obj2.display();
  
    }  
    return 0;
}

