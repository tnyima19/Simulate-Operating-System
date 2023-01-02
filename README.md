OPERATING SYSTEM SIMULATION
Operaint System Simulation is a project which simulates how operating system interacts with CPU,RAM, disk, CPU Scheduling, Processes.

📝 `NOTE - PASTE PART 2 SNIPPET HERE:` Paste the README template for part 2 of this assignment here at the top. This will show a history of your development process, which users stories you completed and how your app looked and functioned at each step.

---

## OPERATING SYSTEM SIMULATION

### User Stories
`TODO://` In the **User Stories section below**, add an `x` in the `-[ ]` like this `- [x]` for any user story you complete. (🚫 Remove this paragraph after checking off completed user stories)

#### REQUIRED (10pts)
- [x] (2pts) Create Process, It goes to the CPU directly if the Readyqueue is empty. If the current process's priority is less than the new process, the new process goes directly to CPU, and the old process goes back to the ReadyQueue
- [x] (5pts) ReadyQueue's queue is based on priority. I used Priority Queue. Similarly if Disk Read Request is called the currently running Process in the CPU goes to the disk and and sends the required string. The Process comes back to the CPU. If DiskJobCompleted is called the process from the disk goes back to ReadyQueue. 
- [x] (3pts) Print RAM, and update RAM.

#### BONUS
- [ ] (2pt) Print the linked list to find out which one is least used frame and most used frame in RAM.


### HOW DOES IT WORK
create an a new .cpp file and include all the required files from the github. 
create an SimulatedOS object and put in the required number of disks, RAM and page Size. and insert processes with required priorities that you like.(for example:
int main(){
SimulatedOS os{1(number of disks), 300(bytes of RAM), 100(page size)};
osSim.NewProcess(10);
osSim.New Process(5);
return 0;

}

### WHAT CAN YOU DO?
- you can create new processes using the function(NewProcess(int priority))
- you can terminate a running process using the function (Exit()).
-you can Print the priority of currently running process using the function (PringCPU()).


### App Walkthrough GIF
`TODO://` Add the URL to your animated app walkthough `gif` in the image tag below, `YOUR_GIF_URL_HERE`. Make sure the gif actually renders and animates when viewing this README. (🚫 Remove this paragraph after after adding gif)


### Notes
Describe any challenges encountered while building the app.
