#include"CPU.h"

 CPU::CPU(){
        Process np(0,0);

        p = np; 
    }
    CPU::CPU(Process curr_process){
        p = curr_process;

    }
    void CPU::UpdatePage(int page){
        p.pageCounter= page;
    }
    void CPU::UpdateFrame(int frame){
        p.frame = frame;
    }

    void CPU::Insert(Process curr_process){
        //std::cout<<"inserted"<<std::endl;
        p = curr_process;
        //ram.update(curr_process.PID, curr_process.priority);
    }
    int CPU::PrintPriority(){
    return p.priority;
    }
    int CPU::PrintID(){
    return p.PID;
    }
    bool CPU::IsEmpty(){
        if(p.PID == 0 && p.priority == 0){
            return true;
        }else
            return false;
    }
    int CPU::GetFrame(){
        return p.frame;
    }
    int CPU::GetPID(){
        return p.PID;
    }
    int CPU::GetPage(){
        return p.pageCounter;
    }
    Process CPU::GetProcess(){
        return p;
    }
    void CPU::Erase(){
        Process new_p(0,0);
        p = new_p;
    }
