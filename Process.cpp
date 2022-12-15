#include "Process.h"

Process::Process(){
    PID = 0;
    priority = 0;
    frame = 0;
}

Process::Process(int processID, int priority){
    
    PID = processID;
    priority = priority;
    //std::cout<<"PID:"<<PID<<std::endl;
    //std::cout<<"priority"<<priority<<std::endl;

}
  Process::Process(int processID, int priority, int new_frame, int page){
        PID = processID;
        this->priority = priority;
        //next = nullptr;
        frame = new_frame;
        pageCounter = page;

        }
  bool Process::operator <(const Process &a) const{
       return a.priority > this->priority;
    }

int Process::GetPriority() const {
        return priority;
    }

int Process::GetPID() const {
        return PID;
    }
void Process::SetFrame(int new_frame){
    frame = new_frame;
}
void Process::SetPageCounter(int new_page){
    pageCounter = new_page;
}
int Process::GetPageCounter(){
    return pageCounter;
}
int Process::GetFrame(){
    return frame;
}


// void friend Process:: std::ostream &operator<(std::ostream &out, const Points2D &some_points2) {
//      //out<<"{";
//       //for(int i=0;i<some_points2.size_;i++)
//      for(size_t y=0;y<some_points2.size_;y++)
//      {
//       out<<"("<<some_points2.sequence_[y][0]<<", "<<some_points2.sequence_[y][1]<<") ";
//      }
//      if(some_points2.sequence_ == nullptr)// when the sequence_ is empty 
//       out<<"()";// if empty return empty bracket
//      out<<std::endl;
//      return out;
//  }