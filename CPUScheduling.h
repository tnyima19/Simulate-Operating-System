/*
Name: Tenzing Nyima
CSCI 340
Date: Dec 14 2022
Project

*/

#ifndef CPUSCHEDULING_H_
#define CPUSCHEDULING_H_
//#include"Process.h"
#include"CPU.h"
//#include"SimulatedOS.h"
#include<iostream>
#include<queue>
//namespace std{
class CPUScheduling{
public:
   CPUScheduling();
   CPUScheduling(Process new_process);
   void Insert(CPU &one_core, Process new_process);
   bool QueueIsEmpty();
   void InsertNextProcess(CPU &a_core);
   void PrintReadyQueue();
   Process GetPriorityProcess();

private:
    std::priority_queue<Process> q;

};
//}
#endif // CPUSCHEDULING_H_
