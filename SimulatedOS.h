//#pragma once
/*
Name: Tenzing Nyima
CSCI 340
Date: Dec 14 2022
Project

*/
#ifndef SIMULATEDOS_H
#define SIMULATEDOS_H
#include"CPUScheduling.h"
#include"RAM.h"
#include"disk.h"
#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>


class SimulatedOS{
public:
    //SimulatedOS();
    SimulatedOS(int diskNum, int RAMAmount, int pages);
    SimulatedOS(int diskNum, int RAMAmount, int pages, int counting);
    void NewProcess(int priority);
    void Exit();
        // remove the process from teh system and free all memory
    void DiskReadRequested(int diskNumber, std::string fileName);
    void printLRU();
    void FetchFrom(unsigned int memoryAddress);
    void DiskJobCompleted(int diskNumber);
    void PrintCPU();
    void PrintReadyQueue();
    void PrintRAM();
        // prints a sorted list of all used frames, page number sorted inti, 
        // and PID of process that owns that page. 
    void PrintDisk(int diskNumber);
    void PrintDiskQueue(int diskNumber);

private:
    int numOfDisk;
    int amountRAM; // amount in bytes.
    int pageSize;
    int count;
    Process np;
    CPU one_core;
    CPUScheduling schedule;
    //int total_disks;
    //CPUScheduling schedule ;
    //CPU one_core;
    std::vector<Disk> disks;
    RAM ram;
    int PageCounter; // ADDRESS IN PROGRAM COUNTER IS LOGICAL ADDRESS,
    int frame;
};
#endif 