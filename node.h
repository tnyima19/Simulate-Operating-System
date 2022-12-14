/*
Name: Tenzing Nyima
CSCI 340
Date: Dec 14 2022
Project

*/

#ifndef NODE_H_
#define NODE_H_
#include<iostream>

struct Node{
    int PID;
    int page;
    //int frame;
    Node(){
        PID = 0;
        page = 0;
        //frame = 0;
    }

    Node(int PID, int new_page){
        this->PID = PID;
        page = new_page;
    }
   // void insert(){
        
    //}
    

};
#endif
