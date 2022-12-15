/*
Name: Tenzing Nyima
CSCI 340
Date: Dec 14 2022
Professor Pavel Shostak
Project on Operating System Simulation

*/

#ifndef NODE_H_
#define NODE_H_
#include<iostream>

struct Node{
    Node();
    Node(int PID, int new_page);
   int GetPID();
   int GetPage();
   void SetPID(int new_PID);
   void SetPage(int new_page);

private:
int PID;
int page;
    

};
#endif
