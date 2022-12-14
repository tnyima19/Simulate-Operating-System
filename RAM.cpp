#include"RAM.h"


RAM::RAM(){
    //frame = 0;
    frame_size = 0;
    total_frame = 0;
}
RAM::RAM(int frameSize){
    frame_size = frameSize;
    //frame = 0;
    total_frame = 0;
    //frame = frame;
    

}

int RAM::GetLRU(){
    return LRU.back();
}

int RAM::GetFront(){
    return LRU.front();
}


void RAM::InsertNoUpdate(int page, int PID, int frame){
     //std::cout<<"i am at insert RAM"<<std::endl;
    //std::cout<<"page: "<<page<<" PID: "<<PID<<std::endl;
    //std::cout<<"Total frame: "<<total_frame<<std::endl;
    //std::cout<<"frameSize: "<<frame_size<<std::endl;
    //std::cout<<"LRU back frame: "<<LRU.back()<<std::endl;
    if(total_frame< frame_size){
        Node new_node(PID,page);
        //table.push_back(new_node);
        table[frame] = new_node;
        //LRU.push_front(frame);
        ++total_frame;
        ++frame;
        
    }else{
        // LRU, DELETE LEAST USED, 
        //std::cout<<"Use LRU"<<std::endl;
        int LRUFrame = LRU.back();
        //std::cout<<LRUFrame<<std::endl;
        //updateFrame(LRUFrame);
        Node new_node(PID, page);
        table[LRUFrame] = new_node;
        //one_core.updateFrame(LRUFrame);

    }
}



//check if all process are present in page[0],
// if they are delete it then update the page and PID, 
void RAM::Insert(int page, int PID, int frame){
    //std::cout<<"i am at insert RAM"<<std::endl;
    //std::cout<<"page: "<<page<<" PID: "<<PID<<std::endl;
    //std::cout<<"Total frame: "<<total_frame<<std::endl;
    //std::cout<<"frameSize: "<<frame_size<<std::endl;
    //std::cout<<"LRU back frame: "<<LRU.back()<<std::endl;
    if(total_frame< frame_size){
        Node new_node(PID,page);
        //table.push_back(new_node);
        table[frame] = new_node;
        LRU.push_front(frame);
        //LRU.pop_back();
        ++total_frame;
        ++frame;
        
    }else{
        // LRU, DELETE LEAST USED, 
       // std::cout<<"Use LRU"<<std::endl;
        int LRUFrame = LRU.back();
        //std::cout<<LRUFrame<<std::endl;
        UpdateFrame(LRUFrame);
        Node new_node(PID, page);
        table[LRUFrame] = new_node;
        //one_core.updateFrame(LRUFrame);

    }
   
   //++frame;
}

void RAM::PrintLRU(){
    std::deque<int> nq = LRU;
    while(!nq.empty()){
        std::cout<<nq.front()<<std::endl;
        nq.pop_front();
    }


}

void RAM::InsertUpdate(CPU &a_core){
   // std::cout<<"i am at insert RAM"<<std::endl;
    //std::cout<<"page: "<<page<<" PID: "<<PID<<std::endl;
    //std::cout<<"Total frame: "<<total_frame<<std::endl;
    //std::cout<<"frameSize: "<<frame_size<<std::endl;
    int frame = a_core.GetFrame();
    int page = a_core.GetPage();
    int PID = a_core.GetPID();
    if(total_frame< frame_size){
        Node new_node(PID,page);
        //table.push_back(new_node);
        table[frame] = new_node;
        //LRU.push_front(frame);
        ++total_frame;
        ++frame;
        
    }else{
        // LRU, DELETE LEAST USED, 
        //std::cout<<"Use LRU"<<std::endl;
        int LRUFrame = LRU.back();
        //updateFrame(frame);
        Node new_node(PID, page);
        table[LRUFrame] = new_node;
        a_core.UpdateFrame(LRUFrame);
        a_core.UpdatePage(page);

    }
   
   //++frame;
}

bool RAM::FindPagePID(int page, int PID){
    // go through the table. 

    auto itr = table.begin();
    while( itr != table.end()){
        if(itr->second.PID == PID && itr->second.page == page){
            return true;
        }
        itr++;
    }

    return false;
}


void RAM::UpdateCPUFramePage(CPU &one_core, int pageCounter,  int frame){
    one_core.UpdatePage(pageCounter);
    one_core.UpdateFrame(LRU.front());
    //std::cout<<"UPDATE CPU FRAME: "<<LRU.front()<<"Page: "<<pageCounter<<std::endl;
    //updateFrame(frame);
}

int RAM::GetFrameSize(){
    return frame_size;
}

void RAM::UpdateFrame(int frame_number){
    auto itr = LRU.begin();

    //if( itr != LRU.end()){// if its already in the linked list, just update it
    while(itr != LRU.end()){
        if(*itr == frame_number){// if found
            LRU.erase(itr);
            LRU.emplace_front(frame_number);
            //std::cout<<"Final frame: "<<frame_number<<std::endl;
            return;
        }
        ++itr;
    }
    // when not found
        // delete the least recently used. 
        LRU.pop_back();
        LRU.push_front(frame_number);
        // update this in RAM. 
        
}

int RAM::GetFrameViaPagePID(int page, int PID){
    auto itr = table.begin();
    while(itr != table.end()){
        if(itr->second.page == page && itr->second.PID == PID)
            return itr->first;

    ++itr;
    }
    return GetLRU();
}
bool RAM::CanFrameViaPagePID(int page, int PID){
auto itr = table.begin();
    while(itr != table.end()){
        if(itr->second.page == page && itr->second.PID == PID)
            return true;

    ++itr;
    }
    return false;


}

void RAM::UpdateFramePage(int page_counter, int process_id, int frame_number  ){
     auto itr = LRU.begin();

    //if( itr != LRU.end()){// if its already in the linked list, just update it
    while(itr != LRU.end()){
        if(*itr == frame_number){// if found
            Node new_node(process_id, page_counter);
            table[frame_number] = new_node;
            //std::cout<<new_node.page<<std::endl;
            //std::cout<<new_node.PID<<std::endl;

            //std::cout<<"i am at UPDATE FRAME PAGE Frame:"<<frame_number<<std::endl;
            UpdateFrame(frame_number);
            //int new_frame = *itr;
            //LRU.erase(itr);
            //LRU.emplace_front(*itr);
            return;
        }
        ++itr;
    }

        //LRU.pop_back();
        //LRU.push_front(frame_number);

}

void RAM::EraseFromMemory(int PID){
    //table[frame].page = 0;
    //table[frame].PID = 0;
    auto i = table.begin();

    while(i != table.end()){

    if(i->second.PID == PID){
        std::cout<<"I am at erase from mem:"<<PID<<std::endl;
        i->second.PID = 0;
        i->second.page = 0;
         int frame = i->first;
        auto itr = LRU.begin();
        while(itr != LRU.end()){
            if(*itr == frame){
                //std::cout<<"ITR: "<<*itr<<std::endl;
                LRU.erase(itr);
            }
            itr++;
        }
        LRU.push_back(frame);
    }
    i++;
    }


}
void RAM::Print(){
    std::cout<<"Frame   "<<"Page    "<<"PID"<<std::endl;
    int count = 0;
    //std::cout<<total_frame<<std::endl;
    //auto itr;
    for(int i=0;i<total_frame;++i){
        //std::cout<<"COUNT: "<<count<<std::endl;
        if(table[i].page == 0 && table[i].PID == 0){
            std::cout<<i<<"         "<<"        "<<std::endl;
        }else{
        std::cout<<i<<"     "<<table[i].page<<"         "<<table[i].PID<<std::endl;
        //++count;
        }
        //++count;
    }
}

