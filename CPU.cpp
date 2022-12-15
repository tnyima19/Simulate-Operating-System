#include"CPU.h"

 CPU::CPU(){
        Process np(0,0);

        p = np; 
    }
    CPU::CPU(Process curr_process){
        p = curr_process;

    }
    void CPU::UpdatePage(int page){
        p.SetPageCounter(page);
    }
    void CPU::UpdateFrame(int frame){
        p.SetFrame(frame);
    }

    void CPU::Insert(Process curr_process){
        //std::cout<<"inserted"<<std::endl;
        p = curr_process;
        //ram.update(curr_process.PID, curr_process.priority);
    }
    int CPU::PrintPriority(){
    return p.GetPriority();
    }
    int CPU::PrintID(){
    return p.GetPID();
    }
    bool CPU::IsEmpty(){
        if(p.GetPID() == 0 && p.GetPriority() == 0){
            return true;
        }else
            return false;
    }
    int CPU::GetFrame(){
        return p.GetFrame();
    }
    int CPU::GetPID(){
        return p.GetPID();
    }
    int CPU::GetPage(){
        return p.GetPageCounter();
    }
    Process CPU::GetProcess(){
        return p;
    }
    void CPU::Erase(){
        Process new_p(0,0);
        p = new_p;
    }
