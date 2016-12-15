//tree.cpp
//Jose Sanchez
//Created on December 13 2016

#include "binaryTree.h"
#include <cstdlib>
#include <iostream>

using namespace std;

//tree constructor
tree::tree()
{
    root = NULL;
}

tree::~tree()
{
    
}

//insert function
void tree::insert(int data, int hit, int x, int y)
{
    //create current node
    //create last node
    Node *current, *last;
    //newNode is new node
    Node *newNode =  new Node;
    //assign data given
    newNode->data = data;
    newNode->hits = hit;
    newNode->xguess = x;
    newNode->yguess = y;
    
    //left and right are NULL
    newNode->left = NULL;
    newNode->right= NULL;
    
    //if nothing in tree
    if(root == NULL)  {
        //root is newNode
        root = newNode;
    }
    else {
        //set current to root
        current = root;    
        //loop through current while not at end
        while(current != NULL) {           
            last = current;
            //if data of current is greater than data given 
            if(current->data > data){
                //move left to show data less than current data of node
                current = current->left;
            }   //else if current data greater than data 
            else if(current->data < data){
                //move right to show data greater than current data of node
                current = current->right; 
            } else if(current->data == data) {
                cout<<data;
                cout<<" in list"<<endl;
                return;
            }    
        }
        //if point in link entry found is greater than data entry
        if(last->data > data) {
           //last's right is newNode
            last->left = newNode;
        } else{
            //last's right is newNode
            last->right = newNode;
        }
    }     
}
