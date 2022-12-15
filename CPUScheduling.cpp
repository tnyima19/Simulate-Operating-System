#include"CPUScheduling.h"


    CPUScheduling::CPUScheduling(){
        //Process np(0,0);
    }
    CPUScheduling::CPUScheduling(Process new_process){
        //std::cout<<new_process.PID<<":"<<new_process.priority<<std::endl;
        q.push(new_process);

    }
    void CPUScheduling::Insert(CPU &one_core, Process new_process){
        if(one_core.GetProcess()< new_process){
            //std::cout<<"in core :"<<one_core.getProcess().PID<<std::endl;
            q.push(one_core.GetProcess());
            one_core.Insert(new_process);
            //std::cout<<"in core :"<<one_core.getProcess().PID<<std::endl;
        }else{
            q.push(new_process);
        }
        //q.push(new_process);
    }

    bool CPUScheduling::QueueIsEmpty(){
        if(q.empty())
            return true;
        
        return false;
    }

    void CPUScheduling::InsertNextProcess(CPU &a_core){
        a_core.Insert(q.top());
        q.pop();
    }
    
    // constructor, to insert new process

    void CPUScheduling::PrintReadyQueue(){
        std::priority_queue<Process> new_q;
        new_q = q;
        
        std::cout<<"Ready-Queue: ";
        while(!new_q.empty()&& new_q.top().GetPriority() != 0){ // something is wrong here,
            int top = new_q.top().GetPID();
            if(top != 0){
            std::cout<<top<<" ";
            
            }
            new_q.pop();
        }
        std::cout<<std::endl;
    }
    Process CPUScheduling::GetPriorityProcess(){
        Process p = q.top();
        q.pop();

        return p;
    }
