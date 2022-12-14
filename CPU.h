/*
Name: Tenzing Nyima
CSCI 340
Date: Dec 14 2022
Project

*/

#ifndef CPU_H_
#define CPU_H_
#include"Process.h"
//#include "CPUScheduling.h"

// SINGLE CORE CPU, 1 PROCESS, PER 
class CPU{
public:
    CPU();
    CPU(Process curr_process);
    void UpdatePage(int page);
    void UpdateFrame(int frame);
    void Insert(Process curr_process);
    int PrintPriority();
    int PrintID();
    bool IsEmpty();
    int GetFrame();
    int GetPID();
    int GetPage();
    Process GetProcess();
    void Erase();
   
private:
    Process p;// doesn't have a default construct
};
#endif
