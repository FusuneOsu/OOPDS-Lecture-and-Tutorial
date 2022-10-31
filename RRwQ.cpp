#include <cstdlib>
#include <iostream>
#include <queue>


using namespace std;
class process
{
public:
    //AT = Arrival Time
    //BT = Burst Time
    //CT = Completion Time
    //TAT = TurnAround Time
    //WT = Waiting Time
    //RT = Respond Time
    //QT = Quantum Time

    //arrivalTime
    //burstTime
    //completionTime
    //turnAroundTime
    //waitingTime
    //respondTime
    //quantumTime

    pid_t p_no = 0;
    time_t start_arrivalTime = 0, arrivalTime = 0,
           burstTime_left = 0, burstTime = 0, temp_burstTime = 0,
           completionTime = 0, turnAroundTime = 0, waitingTime = 0, respondTime = 0;
    int priority = 0;

    // Function for completion time
    void set_completionTime(time_t time)
    {
        completionTime = time;
        set_turnAroundTime();
        set_waitingTime();
    }

    // Function for Turn Around Time
    void set_turnAroundTime()
    {
        turnAroundTime = completionTime - start_arrivalTime;
    }

    // Function for Waiting Time
    void set_waitingTime()
    {
        waitingTime = turnAroundTime - burstTime;
    }
    void P_set()
    {
        start_arrivalTime = arrivalTime;
        burstTime_left = burstTime;
    }
    void set_respondTime(time_t time)
    {
        respondTime = time - start_arrivalTime;
    }

    // Overload operator '<' w.r.t arrival
    // time because arrival time is the
    // first priority even greater than
    // priority of process and priority_queue
    // pops out the greatest value first
    // so we need to replace '<' with '>' inorder
    // to pop out smallest value
    friend bool operator < (const process& a, const process& b)
    {
        return a.arrivalTime > b.arrivalTime;
    }
};

// Function to implement Round Robin algorithm
priority_queue<process> RR_run(priority_queue<process> ready_queue,
                               time_t Time_Slice,
                               queue<process>* gantt)
{
    priority_queue<process> completion_queue;
    process p;
    time_t clock = 0;

    while (!ready_queue.empty())
    {
        while (clock < ready_queue.top().arrivalTime)
        {
            p.temp_burstTime++;
            clock++;
        }
        if (p.temp_burstTime > 0)
        {
            p.p_no = -1;
            p.completionTime = clock;
            (*gantt).push(p);
        }
        p = ready_queue.top();
        ready_queue.pop();

        if (p.arrivalTime == p.start_arrivalTime)
            p.set_respondTime(clock);

        while (p.burstTime_left > 0 && (p.temp_burstTime < Time_Slice
                                 || ready_queue.empty()
                                 || clock < ready_queue.top().arrivalTime))
        {
            p.temp_burstTime++;
            p.burstTime_left--;
            clock++;
        }

        if (p.burstTime_left == 0)
        {
            p.arrivalTime = p.start_arrivalTime;
            p.set_completionTime(clock);
            (*gantt).push(p);
            p.temp_burstTime = 0;
            completion_queue.push(p);
        }
        else
        {
            p.arrivalTime = clock;
            p.completionTime = clock;
            (*gantt).push(p);
            p.temp_burstTime = 0;
            ready_queue.push(p);
        }
    }

    return completion_queue;
}

// Set data on the basis of given table
priority_queue<process> set_sample_data()
{
    int a,b,c,nop;
    cout << "Enter The Number Of Process Between (3-10) : " << endl;
    cin >> nop;

    if(nop == 2 || nop == 1)
    {
        priority_queue<process> ready_queue;
        cout<<"INVALID NO OUTPUT WILL BE COMPUTE"<<endl;
        return ready_queue;
    }

    if(nop==3)
    {
        priority_queue<process> ready_queue;
        process temp;
        cout << endl;
        cout << "PROCESS 1" << endl;  //to enter the value for process,arrival time,burst time and priority.
        temp.p_no = 1;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 2" << endl;
        temp.p_no = 2;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 3" << endl;
        temp.p_no = 3;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        return ready_queue;
    }

    if(nop ==4)
    {
        priority_queue<process> ready_queue;
        process temp;
        cout << endl;
        cout << "PROCESS 1" << endl;  //to enter the value for process,arrival time,burst time and priority.
        temp.p_no = 1;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 2" << endl;
        temp.p_no = 2;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 3" << endl;
        temp.p_no = 3;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 4" << endl;
        temp.p_no = 4;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        return ready_queue;
    }

    if (nop==5)
    {
        priority_queue<process> ready_queue;
        process temp;
        cout << endl;
        cout << "PROCESS 1" << endl;  //to enter the value for process,arrival time,burst time and priority.
        temp.p_no = 1;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 2" << endl;
        temp.p_no = 2;
        cout<<"Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 3" << endl;
        temp.p_no = 3;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 4" << endl;
        temp.p_no = 4;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 5" << endl;
        temp.p_no = 5;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        return ready_queue;

    }

    if(nop==6)
    {
        priority_queue<process> ready_queue;
        process temp;
        cout << endl;
        cout << "PROCESS 1" << endl;  //to enter the value for process,arrival time,burst time and priority.
        temp.p_no = 1;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 2" << endl;
        temp.p_no = 2;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 3" << endl;
        temp.p_no = 3;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 4" << endl;
        temp.p_no = 4;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 5" << endl;
        temp.p_no = 5;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 6" << endl;
        temp.p_no = 6;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        return ready_queue;
    }

    if(nop=7)
    {
        priority_queue<process> ready_queue;
        process temp;
        cout << endl;
        cout << "PROCESS 1" << endl;  //to enter the value for process,arrival time,burst time and priority.
        temp.p_no = 1;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 2" << endl;
        temp.p_no = 2;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 3" << endl;
        temp.p_no = 3;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 4" << endl;
        temp.p_no = 4;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 5" << endl;
        temp.p_no = 5;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 6" << endl;
        temp.p_no = 6;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 7" << endl;
        temp.p_no = 7;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        return ready_queue;
    }

    if(nop==8)
    {
        priority_queue<process> ready_queue;
        process temp;
        cout << endl;
        cout << "PROCESS 1" << endl;  //to enter the value for process,arrival time,burst time and priority.
        temp.p_no = 1;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 2" << endl;
        temp.p_no = 2;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 3" << endl;
        temp.p_no = 3;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 4" << endl;
        temp.p_no = 4;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 5" << endl;
        temp.p_no = 5;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 6" << endl;
        temp.p_no = 6;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 7" << endl;
        temp.p_no = 7;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 8" << endl;
        temp.p_no = 8;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        return ready_queue;
    }

    if(nop==9)
    {
        priority_queue<process> ready_queue;
        process temp;
        cout << endl;
        cout << "PROCESS 1" << endl;  //to enter the value for process,arrival time,burst time and priority.
        temp.p_no = 1;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 2" << endl;
        temp.p_no = 2;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 3" << endl;
        temp.p_no = 3;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 4" << endl;
        temp.p_no = 4;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 5" << endl;
        temp.p_no = 5;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 6" << endl;
        temp.p_no = 6;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 7" << endl;
        temp.p_no = 7;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 8" << endl;
        temp.p_no = 8;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 9" << endl;
        temp.p_no = 9;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        return ready_queue;
    }

    if(nop==10)
    {
        priority_queue<process> ready_queue;
        process temp;
        cout << endl;
        cout << "PROCESS 1" << endl;  //to enter the value for process,arrival time,burst time and priority.
        temp.p_no = 1;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 2" << endl;
        temp.p_no = 2;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 3" << endl;
        temp.p_no = 3;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 4" << endl;
        temp.p_no = 4;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 5" << endl;
        temp.p_no = 5;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 6" << endl;
        temp.p_no = 6;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 7" << endl;
        temp.p_no = 7;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 8" << endl;
        temp.p_no = 8;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 9" << endl;
        temp.p_no = 9;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        cout << "PROCESS 10" << endl;
        temp.p_no = 10;
        cout << "Enter The Arrival time : " << endl;
        cin >> a;
        temp.arrivalTime = a;
        cout << "Enter The Burst Time : " << endl;
        cin >> b;
        temp.burstTime = b;
        cout << "Enter The Priority : " << endl;
        cin >> c;
        temp.priority = c;
        temp.P_set();
        ready_queue.push(temp);

        cout << endl;
        return ready_queue;
    }
}

// Function to get total Waiting Time
double get_total_waitingTime(priority_queue<process> processes)
{
    double total = 0;
    while (!processes.empty())
    {
        total += processes.top().waitingTime;
        processes.pop();
    }
    return total;
}

// Function to get total Turn Around Time
double get_total_turnAroundTime(priority_queue<process> processes)
{
    double total = 0;
    while (!processes.empty())
    {
        total += processes.top().turnAroundTime;
        processes.pop();
    }
    return total;
}

// Function to get total Completion Time
double get_total_completionTime(priority_queue<process> processes)
{
    double total = 0;
    while (!processes.empty())
    {
        total += processes.top().completionTime;
        processes.pop();
    }
    return total;
}

// Function to get total Response Time
double get_total_respondTime(priority_queue<process> processes)
{
    double total = 0;
    while (!processes.empty())
    {
        total += processes.top().respondTime;
        processes.pop();
    }
    return total;
}

// Function to display Completion queue
void disp(priority_queue<process> main_queue, bool high)
{
    int i = 0, temp, size = main_queue.size();
    priority_queue<process> tempq = main_queue;
    double temp1;
    cout << "+=============+==============";
    cout << "+============+=================";
    cout << "+=================+==============+===============+";
    if (high == true)
        cout << "==========+" << endl;
    else
        cout << endl;
    cout << "| Process No. | Arrival Time ";
    cout << "| Burst Time | Completion Time ";
    cout << "| Turnaround Time | Waiting Time | Response Time |";
    if (high == true)
        cout << " Priority |" << endl;
    else
        cout << endl;
    cout << "+=============+==============";
    cout << "+============+=================";
    cout << "+=================+==============+===============+";
    if (high == true)
        cout << "==========+" << endl;
    else
        cout << endl;
    while (!main_queue.empty())
    {
        temp = to_string(main_queue.top().p_no).length();
        cout << '|' << string(6 - temp / 2 - temp % 2, ' ')
             << main_queue.top().p_no << string(7 - temp / 2, ' ');
        temp = to_string(main_queue.top().start_arrivalTime).length();
        cout << '|' << string(7 - temp / 2 - temp % 2, ' ')
             << main_queue.top().start_arrivalTime << string(7 - temp / 2, ' ');
        temp = to_string(main_queue.top().burstTime).length();
        cout << '|' << string(6 - temp / 2 - temp % 2, ' ')
             << main_queue.top().burstTime << string(6 - temp / 2, ' ');
        temp = to_string(main_queue.top().completionTime).length();
        cout << '|' << string(8 - temp / 2 - temp % 2, ' ')                //to put the value inside the table
             << main_queue.top().completionTime << string(9 - temp / 2, ' ');
        temp = to_string(main_queue.top().turnAroundTime).length();
        cout << '|' << string(8 - temp / 2 - temp % 2, ' ')
             << main_queue.top().turnAroundTime << string(9 - temp / 2, ' ');
        temp = to_string(main_queue.top().waitingTime).length();
        cout << '|' << string(7 - temp / 2 - temp % 2, ' ')
             << main_queue.top().waitingTime << string(7 - temp / 2, ' ');
        temp = to_string(main_queue.top().respondTime).length();
        cout << '|' << string(7 - temp / 2 - temp % 2, ' ')
             << main_queue.top().respondTime << string(8 - temp / 2, ' ');

        if (high == true)
        {
            temp = to_string(main_queue.top().priority).length();
            cout << '|' << string(5 - temp / 2 - temp % 2, ' ')
                 << main_queue.top().priority << string(5 - temp / 2, ' ');
        }

        cout << "|\n";
        main_queue.pop();
    }

    cout << "+==============+==============";
    cout << "+============+=================";
    cout << "+=================+==============+===============+";
    if (high == true)
        cout << "==========+";
    cout << endl;
    temp1 = get_total_completionTime(tempq);
    cout << "\nTotal completion time : " << temp1 << endl;
    cout << "Average completion time :  " << temp1 / size << endl;
    temp1 = get_total_turnAroundTime(tempq);
    cout << "\nTotal turnaround time :  " << temp1 << endl;
    cout << "Average turnaround time :  " << temp1 / size << endl;
    temp1 = get_total_waitingTime(tempq);
    cout << "\nTotal waiting time :  " << temp1 << endl;
    cout << "Average waiting time :  " << temp1 / size << endl;
    temp1 = get_total_respondTime(tempq);
    cout << "\nTotal response time : " << temp1 << endl;
    cout << "Average response time :  " << temp1 / size << endl;
}

// Function to display Gantt Chart
void disp_gantt_chart(queue<process> gantt)
{
    int temp, prev = 0;
    queue<process> spaces = gantt;
    cout << "\n\nGantt Chart :- \n\n+";
    while (!spaces.empty())
    {
        cout << string(to_string(spaces.front().p_no).length() + (spaces.front().p_no != -1) + 2 * spaces.front().temp_burstTime, '-') << "+";
        spaces.pop();
    }

    cout << "\n|";
    spaces = gantt;

    while (!spaces.empty())
    {
        cout << string(spaces.front().temp_burstTime, ' ');
        if (spaces.front().p_no == -1)
            cout << "IS" << string(spaces.front().temp_burstTime, ' ') << '|';
        else
            cout << "P" << spaces.front().p_no
                 << string(spaces.front().temp_burstTime, ' ') << '|';
        spaces.pop();
    }

    spaces = gantt;
    cout << "\n+";

    while (!spaces.empty())
    {
        cout << string(to_string(spaces.front().p_no).length() + (spaces.front().p_no != -1) + 2 * spaces.front().temp_burstTime, '-') << "+";
        spaces.pop();
    }

    spaces = gantt;
    cout << "\n0";

    while (!spaces.empty())
    {
        temp = to_string(spaces.front().completionTime).length();
        cout << string(to_string(spaces.front().p_no).length() + (spaces.front().p_no != -1) + 2 * spaces.front().temp_burstTime - temp / 2 - prev, ' ')
             << spaces.front().completionTime;
        prev = temp / 2 - temp % 2 == 0;
        spaces.pop();
    }

    cout << "\n\n";
}

// Driver Code
int main()
{

    cout << "+================================================+" << endl;
    cout << "|     Round Robin CPU Scheduling Algorithm       |" << endl;
    cout << "+================================================+" << endl << endl;

    // Initialise Ready and Completion Queue
    priority_queue<process> ready_queue, completion_queue;

    // queue for Gantt Chart
    queue<process> gantt;

    int quantumTime;
    cout << "Enter The Quantum Time Value : " << endl;
    cin >> quantumTime;
    cout << endl;

    ready_queue = set_sample_data();
    cout << endl;

    // Function call to find completion data
    completion_queue = RR_run(ready_queue, quantumTime, &gantt);
    cout << endl;

    // Display Completion Queue
    disp(completion_queue, false);
    cout << endl;

    //cout << "Time Quantum for round robin :  " << quantumTime << endl;

    // Display Gantt Chart
    disp_gantt_chart(gantt);
    cout << endl;

    return 0;
}
