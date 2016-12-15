/* 
 * File:   binaryTree.h
 * Author: Jose
 * Created on December 13 2016
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H


//node structure
struct Node 
{
    int data; //holds data turn data
    int hits; //hold number of hits
    int xguess; //hold x position guess
    int yguess; //hold y position guess
    Node* left; //lower value
    Node* right; //right value/higher value
};
#endif /* BINARYTREE_H */


//tree class 
class tree
{
private:
    Node *root;
public:
    tree();
    ~tree();
    //returns tree
    Node *rtrnNode(){return root;}
    //inserts integer
    void insert(int d, int h, int x, int y); //insert to tree 
};