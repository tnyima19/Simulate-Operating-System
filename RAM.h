/*
Name: Tenzing Nyima
CSCI 340
Date: Dec 14 2022
Professor Pavel Shostak
Project on Operating System Simulation

*/

#ifndef RAM_H_
#define RAM_H_
#include<iostream>
#include<map>
#include<deque>
#include<vector>
#include<stdlib.h>
#include<iterator>
#include"node.h"
#include"CPU.h"

class RAM{
public: 
    RAM();
    RAM(int frameSize);
    int GetLRU();
    int GetFront();
    void InsertNoUpdate(int page, int PID, int frame);
    void Insert(int page, int PID, int frame);
    void PrintLRU();
    void InsertUpdate(CPU &a_core);
    void UpdateCPUFramePage(CPU &one_core, int pageCounter, int frame);
    int GetFrameSize();
    void UpdateFrame(int frame_number);
    int GetFrameViaPagePID(int page, int PID);
    bool CanFrameViaPagePID(int page, int PID);
    bool FindPagePID(int page, int PID);
    void UpdateFramePage(int page_counter, int process_id, int frame_number);
    void EraseFromMemory(int PID);
    void Print();

private:
//int frame;
int total_frame;
int frame_size;
//int amountRAM;
std::map<int, Node> table;// frame | node(PID, page)
std::deque<int> LRU; // linked list of frame numbers, 


};
#endif