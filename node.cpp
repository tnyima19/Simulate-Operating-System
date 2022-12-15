#include"node.h"
 Node::Node(){
        PID = 0;
        page = 0;
    }

  Node::Node(int PID, int new_page){
        this->PID = PID;
        page = new_page;
    }

int Node::GetPage(){
    return page;
}
int Node::GetPID(){
    return PID;
}

void Node::SetPID(int new_PID){
    PID = new_PID;
}
void Node::SetPage(int new_page){
    page = new_page;
}