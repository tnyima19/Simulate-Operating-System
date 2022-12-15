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
    Process();
    Process(int processID, int priority);
    Process(int processID, int priority, int new_frame, int page);
    bool operator <(const Process &a) const;
    int GetPriority() const ;
    int GetPID() const ;
    int GetPageCounter();
    int GetFrame();
    void SetFrame(int new_frame);
    void SetPageCounter(int new_page);
    
private:
    int PID;// starts from 1
    int priority;
    int frame;
    int pageCounter;
};
#endif  
