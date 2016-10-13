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
    SimpleVector  obj1(10);
    obj1.display();

    cout<<"Simple vector with linked lists"<<endl;
    
    cout<<"push back 2 5 times"<<endl;
    for(int i=0; i<5; i++)
    {
        obj1.pushback(i+10);
        obj1.display();
  
    }  
    
    cout<<"pop off last in line 5 times"<<endl;
    for(int i=0; i<8; i++)
    {
        obj1.popoff();
        obj1.display();
  
    }
    cout<<"Dr. Lehr, destroying the list in the destructor resulted in"
            " run failed after program had done what was asked"<<endl;
    cout<<"Works fine with destroying list, but leaks since it was not"
            " destroyed" <<endl;
    return 0;
}

