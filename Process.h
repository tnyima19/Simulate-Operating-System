/*
Name: Tenzing Nyima
CSCI 340
Date: Dec 14 2022
Professor Pavel Shostak
Project on Operating System Simulation

*/

#ifndef PROCESS_H_
#define PROCESS_H_
#include<iostream>
#include<vector>
#include<map>
#include<queue>

struct Process{
//public:
    Process(){
        PID = 0;
        priority = 0;
        frame = 0;
        //PC = 0;
        //count = 1;
    }
    Process(int processID, int priority){
        PID = processID;
        this->priority = priority;
        //next = nullptr;

        //PC = programCounter;
        //count++;

        }// constructor
    //int getpriority();
    //int getPID();
    //Process* getNext();
    Process(int processID, int priority, int new_frame, int page){
        PID = processID;
        this->priority = priority;
        //next = nullptr;
        frame = new_frame;
        pageCounter = page;

        }
    bool operator <(const Process &a) const{
       return a.priority > this->priority;
    }
//private:
    int PID;// starts from 1
    int priority;
    int frame;
    int pageCounter;
};
#endif  
