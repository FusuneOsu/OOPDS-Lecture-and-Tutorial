#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;


class Gantt{
	
	public:
	
	string name;
	int start_time;
	int end_time;
	
	Gantt(){
			
	}
		
	Gantt(string n, int s, int e){
			
		name = n;
		start_time = s;
		end_time = e;
			
	}

};


class GanttChart{

	public:
		
	vector<Gantt> gantt_events;
	
	void drawGantt(){
		
		cout<<"\n~~~~~~~~~GANTT CHART~~~~~~~~~\n";
		
		int n,s,d;
		cout<<endl;
		for(int i=0; i<gantt_events.size(); i++){
			
			n = gantt_events[i].name.length();
			n = n%2==0 ? n:n+1;
			s = ((gantt_events[i].end_time-gantt_events[i].start_time)) - n/2;
			s = s%2==0 ? s:s+1;
			cout<<left<<setfill('-')<<" "<<setw(2*s+n)<<"";
			
		}
		cout<<setfill(' ');
		cout<<endl;
		for(int i=0; i<gantt_events.size(); i++){
			
			n = gantt_events[i].name.length();
			n = n%2==0 ? n:n+1;
			s = ((gantt_events[i].end_time-gantt_events[i].start_time)) - n/2;
			s = s%2==0 ? s:s+1;
			cout<<left<<setw(1)<<"|"<<setw(s)<<""<<gantt_events[i].name<<setw(s)<<"";
			
		}
		cout<<"|"<<endl;
		for(int i=0; i<gantt_events.size(); i++){
			
			n = gantt_events[i].name.length();
			n = n%2==0 ? n:n+1;
			s = ((gantt_events[i].end_time-gantt_events[i].start_time)) - n/2;
			s = s%2==0 ? s:s+1;
			cout<<left<<setfill('-')<<" "<<setw(2*s+n)<<"";
			
		}
		
		cout<<endl;
		for(int i=0; i<gantt_events.size(); i++){
			
			n = gantt_events[i].name.length();
			n = n%2==0 ? n:n+1;
			s = ((gantt_events[i].end_time-gantt_events[i].start_time)) - n/2;
			s = s%2==0 ? s:s+1;
			d = gantt_events[i].start_time==0 ? 1 : log10(gantt_events[i].start_time)+1;
			d--;
			cout<<left<<setfill(' ')<<gantt_events[i].start_time<<setw(2*s+n-d)<<"";
			
		}
		
		cout<<gantt_events[gantt_events.size()-1].end_time<<endl;

		
	}
	
	
};

struct Process{
	
	string name;
	int arrival_time;
	int burst_time;
	int priority;
	int time_at_cpu;
	int time_remaining;
	int finishing_time;
	int turnaround_time;
	int waiting_time;
	int last_start;
	int last_end;
};



class QNode{
	
	public:
		Process* data;
		QNode* next;
};

//Queue For Round Robin / SJF / Priority
class Queue{
	
	QNode* front;
	QNode* rear;
	char mode;
	
	public:
		
		Queue(){
			
			front = NULL;
			rear = NULL;
			
		}
		
		Queue(char m){
			
			front = NULL;
			rear = NULL;
			mode = m;
			
		}
		
		void Enqueue(Process* val){
			
			QNode* newNode = new QNode;
			newNode->next = NULL;
			newNode->data = val;
			
			if(isEmpty()){
				
				front = newNode;
				rear = newNode;
			}
			
			else{

				if(mode=='r'){
				
					rear->next = newNode;
					rear = newNode;
				}
				
				else if(mode=='s'){
					
					if(front->data->burst_time > val->burst_time){
						
						newNode->next = front;
						front = newNode;
					}
					
					else{
					
					 	QNode* curr = front;
	
						while(curr->next && curr->next->data->burst_time <= val->burst_time)
							curr = curr->next;
						
						newNode->next = curr->next;
						curr->next = newNode;
					}
				}
				
				else if(mode=='p'){
					
					if(front->data->priority > val->priority){
						
						newNode->next = front;
						front = newNode;
					}
					
					else{
					
					 	QNode* curr = front;
	
						while(curr->next && curr->next->data->priority <= val->priority)
							curr = curr->next;
						
						newNode->next = curr->next;
						curr->next = newNode;
					}
				}
			}
			
		}
		
		void incrementWaitingTime(){
			
			
			QNode* curr = front;
			
			while(curr){
				
				curr->data->waiting_time++;
				curr = curr->next;
			}
			
		}
		
		Process* Dequeue(){
			
			if(isEmpty()){
				return NULL;
			}
			
			
			else{
				QNode* temp = front;
				Process* val = temp->data;
				front = front->next;

				if(isEmpty())
					rear=NULL;
				
				return val;
				
			}
		}
		
		bool isEmpty(){
			
			return front==NULL;
		}
		
		void printQueue(){
			
			QNode* curr = front;
			
			
			while(curr){
				
				cout<<curr->data->name<<"\t";
				curr= curr->next;
			}
			cout<<endl;
			
		}
		
	
};


//Scheduler
class Scheduler{
	
	
	Process* processes;
	int num_proc;
	Queue ready_queue_RR;
	Queue ready_queue_SJF;
	Queue ready_queue_Priority;
	Process* curr_process;
	int quantum;
	int total_turnaround_time;
	int total_waiting_time;
	public:
		
		Scheduler() : ready_queue_RR('r'), ready_queue_SJF('s'),ready_queue_Priority('p'){
		
			curr_process = NULL;
			
		}
		
		
		void setProcesses(Process* p){
			
			processes = p;
			
		}
	
		void setNumProcesses(int n){
			num_proc = n;
		}
	
		void setQuantum(int q){
			
			quantum=q;
		}
	
		void execRoundRobin(){
			
			GanttChart gChart;
			
			cout<<"-------------------------------------------ROUND-ROBIN------------------------------------------------\n";
			int completed=0;
			
			for(int t=0; completed!=num_proc; t++){
				
				//Check for Arrival of Any Process
				for(int i=0; i<num_proc; i++){
					
					if(processes[i].arrival_time == t){						
						ready_queue_RR.Enqueue(&processes[i]);
					}
					
				}
				
				//Checking For Process Termination
				if(curr_process && curr_process->time_remaining==0){
					
						curr_process->finishing_time = t;
						completed++;
						curr_process->last_end = t;
						Gantt G(curr_process->name, curr_process->last_start, curr_process->last_end);
						gChart.gantt_events.push_back(G);
						curr_process=NULL;
						
				}
				
				//Checking if CPU IDLE			
				if(!curr_process){
					
					if(!ready_queue_RR.isEmpty()){
						curr_process = ready_queue_RR.Dequeue();
						curr_process->time_at_cpu=0;
						curr_process->last_start = t;
					}
					
				}

				//Checking For Timeout
				if(curr_process && curr_process->time_at_cpu==quantum){
					
					ready_queue_RR.Enqueue(curr_process);
					curr_process->last_end = t;
					
					Gantt G(curr_process->name, curr_process->last_start, curr_process->last_end);
					gChart.gantt_events.push_back(G);
					
					if(!ready_queue_RR.isEmpty()){
						curr_process = ready_queue_RR.Dequeue();
						curr_process->time_at_cpu=0;
						curr_process->last_start = t;
					}
				
						
				}

				//Increasing CPU Time of Current Process
				if(curr_process){
					curr_process->time_at_cpu++;
					curr_process->time_remaining--;
				}
				
				
				//Increment Waiting Time For All Processes in Queues
				ready_queue_RR.incrementWaitingTime();
				
				
			}
			
			calculateTurnaroundTime();
			printTable();
			calculateTotalAvgTimes();
			gChart.drawGantt();
			
			
			
		}
		
		
		void execSJF(){
			
			GanttChart gChart;
			
			cout<<endl;
			cout<<"---------------------------------------SJF (Non Preemptive)--------------------------------------------\n";

			int completed=0;

			for(int t=0; completed!=num_proc; t++){
				
				//Check for Arrival of Any Process
				for(int i=0; i<num_proc; i++){
					
					if(processes[i].arrival_time == t){						
						ready_queue_SJF.Enqueue(&processes[i]);
					}
					
				}
				
				//Checking For Process Termination
				if(curr_process && curr_process->time_remaining==0){
					
						curr_process->finishing_time = t;
						completed++;
						curr_process->last_end = t;
						Gantt G(curr_process->name, curr_process->last_start, curr_process->last_end);
						gChart.gantt_events.push_back(G);
						curr_process=NULL;
						
				}
				
				//Checking if CPU IDLE			
				if(!curr_process){
					
					if(!ready_queue_SJF.isEmpty()){
						curr_process = ready_queue_SJF.Dequeue();
						curr_process->time_at_cpu=0;
						curr_process->last_start = t;
					}
					
				}

				//Increasing CPU Time of Current Process
				if(curr_process){
					curr_process->time_at_cpu++;
					curr_process->time_remaining--;
				}
				
				
				//Increment Waiting Time For All Processes in Queues
				ready_queue_SJF.incrementWaitingTime();
				
				
			}
			
			
			calculateTurnaroundTime();
			printTable();
			calculateTotalAvgTimes();
			gChart.drawGantt();
		}
		
		void execPriority(){
			
			GanttChart gChart;
			
			cout<<endl;
			cout<<"---------------------------------------Priority (Non Preemptive)--------------------------------------------\n";

			int completed=0;

			for(int t=0; completed!=num_proc; t++){
				
				//Check for Arrival of Any Process
				for(int i=0; i<num_proc; i++){
					
					if(processes[i].arrival_time == t){							
						ready_queue_Priority.Enqueue(&processes[i]);
					}
					
				}
				
				//Checking For Process Termination
				if(curr_process && curr_process->time_remaining==0){
					
						curr_process->finishing_time = t;
						completed++;
						curr_process->last_end = t;
						Gantt G(curr_process->name, curr_process->last_start, curr_process->last_end);
						gChart.gantt_events.push_back(G);
						curr_process=NULL;
						
				}
				
				//Checking if CPU IDLE			
				if(!curr_process){
					
					if(!ready_queue_Priority.isEmpty()){						
						curr_process = ready_queue_Priority.Dequeue();
						curr_process->time_at_cpu=0;
						curr_process->last_start = t;
					}
					
				}

				//Increasing CPU Time of Current Process
				if(curr_process){
					curr_process->time_at_cpu++;
					curr_process->time_remaining--;
				}
				
				
				//Increment Waiting Time For All Processes in Queues
				ready_queue_Priority.incrementWaitingTime();
			
			}
			
			
			calculateTurnaroundTime();
			printTable();
			calculateTotalAvgTimes();
			gChart.drawGantt();
			
		}
	
	
		void calculateTurnaroundTime(){
			
			for(int i=0; i<num_proc; i++){
				
				processes[i].turnaround_time = processes[i].finishing_time-processes[i].arrival_time;
			}
		}
		
		void printTable(){
			
			cout<<endl;
			cout<<left<<setfill('-')<<setw(3)<<""<<setw(4)<<""<<setw(4)<<""<<"+"<<setw(2)<<""<<setw(12)<<""<<setw(2)<<""<<"+"<<setw(3)<<""<<setw(10)<<""<<setw(3)<<""<<"+"<<setw(2)<<""<<setw(14)<<""<<setw(2)<<""<<"+"<<setw(2)<<""<<setw(15)<<""<<setw(1)<<""<<"+"<<setw(3)<<""<<setw(13)<<""<<setw(2)<<""<<"+"<<endl;
			cout<<setfill(' ');
			cout<<left<<setw(3)<<""<<setw(4)<<"Name"<<setw(4)<<""<<"|"<<setw(2)<<""<<setw(12)<<"Arrival Time"<<setw(2)<<""<<"|"<<setw(3)<<""<<setw(10)<<"Burst Time"<<setw(3)<<""<<"|"<<setw(2)<<""<<setw(14)<<"Finishing Time"<<setw(2)<<""<<"|"<<setw(2)<<""<<setw(15)<<"Turnaround Time"<<setw(1)<<""<<"|"<<setw(3)<<""<<setw(13)<<"Waiting Time"<<setw(2)<<""<<"|"<<endl;
			cout<<left<<setfill('-')<<setw(3)<<""<<setw(4)<<""<<setw(4)<<""<<"+"<<setw(2)<<""<<setw(12)<<""<<setw(2)<<""<<"+"<<setw(3)<<""<<setw(10)<<""<<setw(3)<<""<<"+"<<setw(2)<<""<<setw(14)<<""<<setw(2)<<""<<"+"<<setw(2)<<""<<setw(15)<<""<<setw(1)<<""<<"+"<<setw(3)<<""<<setw(13)<<""<<setw(2)<<""<<"+"<<endl;
			cout<<setfill(' ');
			
			for(int i=0; i<num_proc; i++){
				
				cout<<left<<setw(4)<<""<<setw(3)<<processes[i].name<<setw(4)<<""<<"|"<<setw(6)<<""<<setw(4)<<processes[i].arrival_time<<setw(6)<<""<<"|"<<setw(6)<<""<<setw(4)<<processes[i].burst_time<<setw(6)<<""<<"|"<<setw(7)<<""<<setw(4)<<processes[i].finishing_time<<setw(7)<<""<<"|"<<setw(7)<<""<<setw(4)<<processes[i].turnaround_time<<setw(7)<<""<<"|"<<setw(7)<<""<<setw(4)<<processes[i].waiting_time<<setw(7)<<""<<"|"<<endl;
				cout<<left<<setfill('-')<<setw(3)<<""<<setw(4)<<""<<setw(4)<<""<<"+"<<setw(2)<<""<<setw(12)<<""<<setw(2)<<""<<"+"<<setw(3)<<""<<setw(10)<<""<<setw(3)<<""<<"+"<<setw(2)<<""<<setw(14)<<""<<setw(2)<<""<<"+"<<setw(2)<<""<<setw(15)<<""<<setw(1)<<""<<"+"<<setw(3)<<""<<setw(13)<<""<<setw(2)<<""<<"+"<<endl;
				cout<<setfill(' ');
			}
		}
		
		void calculateTotalAvgTimes(){
			
			total_turnaround_time=0;
			total_waiting_time=0;
		
			for(int i=0; i<num_proc; i++){
				
				total_turnaround_time+=processes[i].turnaround_time;
				total_waiting_time+=processes[i].waiting_time;
			}
			
			cout<<endl;
			cout<<"==> Total Turnaround Time   = "<<total_turnaround_time<<endl;
			cout<<"==> Average Turnaround Time = "<<(double)total_turnaround_time/num_proc<<endl;
			cout<<"==> Total Waiting Time      = "<<total_waiting_time<<endl;
			cout<<"==> Average Waiting Time    = "<<(double)total_waiting_time/num_proc<<endl;
			
		}
		
		void reset(){
			
			for(int i=0; i<num_proc; i++){
				processes[i].time_remaining = processes[i].burst_time;
				processes[i].waiting_time = 0;
				processes[i].finishing_time = 0;
				processes[i].turnaround_time=0;
				processes[i].time_at_cpu=0;
			}
			
		}
	
};



int main(){
		
	int choice, num_proc, q;
	Scheduler sched;
	Process* processes;
	
	while(true){
	
		do{
	
			cout<<"Press 1 for Round-Robin\n";
			cout<<"Press 2 for SJF (Non-Preemptive)\n";
			cout<<"Press 3 for Priority (Non-Preemptive)\n";
			cin>>choice;
		
			if(choice<1 || choice>3)
				cout<<"\nINAVLID INPUT-----Enter Again!!\n\n";
		
		}while(choice<1 || choice>3);
		
		
		
		do{
			cout<<"Enter Number of Processes (3-10): ";
			cin>>num_proc;
				
			if(num_proc<3 || num_proc>10)
				cout<<"\nINAVLID INPUT-----Enter Again!!\n\n";
				
		}while(num_proc<3 || num_proc>10);
			cout<<endl;
				
		processes = new Process[num_proc];
		for(int i=0; i<num_proc; i++){
					
			cout<<"Enter Name of Process-"<<i+1<<"        :   ";
			cin>>processes[i].name;
			cout<<"Enter Arrival Time of Process-"<<i+1<<":   ";
			cin>>processes[i].arrival_time;
			cout<<"Enter Burst Time of Process-"<<i+1<<"  :   ";
			cin>>processes[i].burst_time;
			
			if(choice==3){
				cout<<"Enter Priority of Process-"<<i+1<<"    :   ";
				cin>>processes[i].priority;
			}
			cout<<endl;
	
		}
			
		if(choice==1){
		
			do{
				cout<<"Enter Quantum For Round-Robin: ";
				cin>>q;
					
				if(q<=0)
					cout<<"\nINAVLID INPUT-----Enter Again!!\n\n";
					
			}while(q<=0);
			
			sched.setQuantum(q);
		}
				
		sched.setProcesses(processes);
		sched.setNumProcesses(num_proc);
		sched.reset();
		
		if(choice==1)
			sched.execRoundRobin();
			
		else if(choice==2)
			sched.execSJF();
	
		else if(choice==3)
			sched.execPriority();
			
		do{
			
			cout<<"\nPress 1 To Run Another Algorithm\n";
			cout<<"Press 2 To Exit\n";
			cin>>choice;
				
			if(choice!=1 && choice!=2)
				cout<<"\nINAVLID INPUT-----Enter Again!!\n\n";
					
		}while(choice!=1 && choice!=2);
			
		if(choice==2)
			exit(0);
		else
			system("CLS");
	}

}
