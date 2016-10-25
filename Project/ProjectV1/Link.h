/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Link.h
 * Author: Jose
 *
 * Created on October 24, 2016, 2:02 PM
 */
#ifndef LINK_H
#define LINK_H
#include <string>
using namespace std;

struct Link
{
    string name;    //keeps name of user
    int score;      //keeps score of user
    Link * next;     //next pointer
    
};

#endif /* LINK_H */

