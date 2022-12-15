#include"disk.h"

    Disk::Disk(){
        words = "";
        diskNum = 0;
    }

 Disk::Disk(Process newProcess, int num){
        q.push(newProcess);
        //processes = newProcess;
        diskNum = num;
        words = "";
    }
    void Disk::pop(){
        q.pop();
    }
    void Disk::SetWord(std::string new_word){
        words = new_word;
    }
    void Disk::push(Process p){
        q.push(p);
    }
    Process Disk::front(){
        return q.front();
    }
    bool Disk::CheckQueueEmpty(){
        if(q.empty()){
            return true;
        }
        return false;
    }
    std::queue<Process> Disk::GetQueue(){
        return q;
    } 
    void Disk::GetWords(){
         std::cout<<words;
    }
