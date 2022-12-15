/*
Name: Tenzing Nyima
CSCI 340
Date: Dec 14 2022
Professor Pavel Shostak
Project on Operating System Simulation

*/

#ifndef DISK_H_
#define DISK_H_
#include"Process.h"
#include<iostream>

struct Disk{
    Disk();
    Disk(Process newProcess, int num);
    void pop();
    void push(Process p);
    Process front();
    void SetWord(std::string new_word);
    bool CheckQueueEmpty();
    void GetWords();
    std::queue<Process> GetQueue();
    
    //Process processes;
private:
    int diskNum;
    std::string words;
    std::queue<Process> q;
    

};
#endif

