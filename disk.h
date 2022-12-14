/*
Name: Tenzing Nyima
CSCI 340
Date: Dec 14 2022
Project

*/

#ifndef DISK_H_
#define DISK_H_
#include"Process.h"
#include<iostream>

struct Disk{
    Disk(){
        
    }
    Disk(Process newProcess, int num){
        q.push(newProcess);
        //processes = newProcess;
        diskNum = num;
        words = "";
    }
    void pop(){
        q.pop();
    }
    void push(Process p){
        q.push(p);
    }
    Process front(){
        return q.front();
    }

    
    //Process processes;
    int diskNum;
    std::string words;
    std::queue<Process> q;
    

};
#endif

