#include"SimulatedOS.h"


SimulatedOS::SimulatedOS(int diskNum, int RAMAmount, int pages){
      numOfDisk = diskNum;
        amountRAM = RAMAmount;
        pageSize = pages;
        count = 0;
        Process n(0,0);
        np = n;
        CPU a_core(np);
        one_core = a_core;
        CPUScheduling sche;
        schedule = sche;
        std::vector<Disk> d(diskNum);
        disks = d;
        int frameSize = amountRAM/pageSize;
        //total_disks = 0;
        PageCounter = 0;
        RAM ram2(frameSize);
        ram  = ram2;
        frame = 0;
}

SimulatedOS::SimulatedOS(int diskNum, int RAMAmount, int pages, int counting){
     numOfDisk = diskNum;
        //std::vector<Disk> diskTotal(diskNum);
        std::vector<Disk> d(diskNum);
        frame = 0;
        disks = d;
        amountRAM = RAMAmount;
        pageSize = pages;
        count = counting;
         Process n(0,0);
        np = n;
        CPU a_core(np);
        one_core = a_core;
        CPUScheduling sche;
        schedule = sche;

        int frameSize = amountRAM/pageSize;
        //total_disks = 0;
        RAM ram2(frameSize);
        ram = ram2;
        PageCounter = 0;
}

void SimulatedOS::NewProcess(int priority){
     ++count;
        //std::cout<<"Process stage"<<std::endl;
        if(frame>=ram.GetFrameSize()){
            frame = ram.GetLRU();
        }
        int page_number = 0;

        Process new_process{count, priority,frame,page_number };

        // check if CPU IS EMPTY
        if(one_core.IsEmpty()){
            //std::cout<<"core is empty"<<std::endl;
            one_core.Insert(new_process);
            
            //int page_number = 0;
            int processid = new_process.PID;
            //std::cout<<"right before ram"<<std::endl;
            ram.Insert(page_number, processid, frame);
            ++frame;
        
        }else{
            if(one_core.GetProcess()<new_process){
                Process temp = one_core.GetProcess();
                one_core.Insert(new_process);
                if(temp.PID != 0 && temp.priority != 0){ // TO CHECK IF CPU IS IDLE IF pid = 0 and priority == 0 its idle
                    schedule.Insert(one_core, temp);// 
                }
            int page_number = 0;    
            int processid = new_process.PID;
            ram.Insert(page_number, processid,frame);
            frame++;

            }else{
                int page_number = 0;    
                int processid = new_process.PID;
                schedule.Insert(one_core, new_process);
                ram.Insert(page_number, processid,frame);
                frame++;
            }
        }

}

void SimulatedOS::Exit(){
   Process process_to_quit = one_core.GetProcess();
        if(!schedule.QueueIsEmpty()){
            
            schedule.InsertNextProcess(one_core);

        }else{
            //Process process_to_quit = one_core.getProcess();
            one_core.Erase();
        }
        ram.EraseFromMemory(process_to_quit.PID);
}
void SimulatedOS::DiskReadRequested(int diskNumber, std::string fileName){
    // no file reading only simulation, 
       // currently running process requests to read the specifed file from the disk 
        // with a given number, 

        // we need disk and RAM etc. 
        disks[diskNumber].words = fileName;
        disks[diskNumber].push(one_core.GetProcess());
 
        one_core.Erase();// empty the process, 
        one_core.Insert(schedule.GetPriorityProcess());
        ram.UpdateFramePage(one_core.GetPage(), one_core.GetPID(), one_core.GetFrame());
}
void SimulatedOS::printLRU(){
    ram.PrintLRU();
}
void SimulatedOS::FetchFrom(unsigned int memoryAddress){
        PageCounter = memoryAddress/ pageSize;
       if(!ram.FindPagePID(PageCounter, one_core.GetPID())){
        ram.Insert(PageCounter,one_core.GetProcess().PID,frame);
        one_core.UpdatePage(PageCounter);
        one_core.UpdateFrame(ram.GetFront()); // because ram is already inserted, and frame palce is updated
        ++frame;
       }else{ // if found, 
            //std::cout<<"ONE CORE "<<one_core.getFrame()<<std::endl;
            int updateFrame = ram.GetFrameViaPagePID(PageCounter, one_core.GetPID());
            ram.UpdateFrame(updateFrame);
       }
}
void SimulatedOS::DiskJobCompleted(int diskNumber){
 // the process on top of the FIFO list, returns back to the ready queu. 
        //std::cout<<disks[diskNumber].q.front().PID<<std::endl;
        if(!disks[diskNumber].q.empty()){
        Process disk_process = disks[diskNumber].q.front();
       

        schedule.Insert(one_core, disk_process);
        disks[diskNumber].q.pop();
        if(!ram.CanFrameViaPagePID(disk_process.pageCounter, disk_process.PID)){

        //update it in ram. 
         //std::cout<<"DISK JOB COMPLETED: "<<disk_process.frame<<"PID:"<<disk_process.PID<<"PAGECOUNTER: "<<disk_process.pageCounter<<std::endl;
        ram.Insert(disk_process.pageCounter, disk_process.PID, disk_process.frame); //THIS IS CORRECT
        ram.UpdateCPUFramePage(one_core, disk_process.pageCounter, disk_process.frame); //
        }else{
            // if we can find it just update the particular frame number to the top. 
            ram.UpdateFrame(disk_process.frame);

        }
        }else{
            // empty
            std::cout<<"Disk is empty "<<std::endl;
        }
}

void SimulatedOS::PrintCPU(){
    if(one_core.IsEmpty()){
            std::cout<<"CPU  is currently empty."<<std::endl;
            return;
        }
        std::cout<<"CPU:"<<one_core.PrintID()<<" "<<std::endl;

}
void SimulatedOS::PrintReadyQueue(){
    //schedule.printReadyQueue();
         if(schedule.QueueIsEmpty()){
            std::cout<<"Ready Queue is empty"<<std::endl;
            return;
        }
        schedule.PrintReadyQueue();


}
void SimulatedOS::PrintRAM(){
     ram.Print();

}
void SimulatedOS::PrintDisk(int diskNumber){
       if(disks[diskNumber].q.empty()){
            std::cout<<"Disk "<<diskNumber<<": Idle"<<std::endl;
            return;
        }

        std::cout<<"Disk "<<diskNumber<<": ";
        Process p = disks[diskNumber].q.front();
        // total_disks++;
        std::cout<<"PID "<< p.PID<<","<<disks[diskNumber].words<<std::endl;



}
void SimulatedOS::PrintDiskQueue(int diskNumber){

        // print the qaueue in theD
        //std::cout<<"i am at PRINT DISK QUEUE:"<<std::endl;
        if(diskNumber > numOfDisk){
            std::cout<<"Instruction ignored: no disk with such number exists"<<std::endl;
            return;
        }
        std::queue<Process> q = disks[diskNumber].q;
        q.pop();// because we only print the next one to be served
        if(q.empty()){
            std::cout<<"Disk "<<diskNumber<<" I/O-queue: Empty"<<std::endl;
		//return;
        }else{
        
        while(!q.empty()){
            std::cout<<"PID: "<<q.front().PID<<std::endl;
            q.pop();
        }
        }

}
