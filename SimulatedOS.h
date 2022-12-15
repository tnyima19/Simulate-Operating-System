/*
Name: Tenzing Nyima
CSCI 340
Date: Dec 14 2022
Professor Pavel Shostak
Project on Operating System Simulation

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
    SimulatedOS(int diskNum, int RAMAmount, int pages);
    SimulatedOS(int diskNum, int RAMAmount, int pages, int counting);
    void NewProcess(int priority);
    void Exit();
    void DiskReadRequested(int diskNumber, std::string fileName);
    void PrintLRU();
    void FetchFrom(unsigned int memoryAddress);
    void DiskJobCompleted(int diskNumber);
    void PrintCPU();
    void PrintReadyQueue();
    void PrintRAM();
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
    std::vector<Disk> disks;
    RAM ram;
    int PageCounter; 
    int frame;
};
#endif 