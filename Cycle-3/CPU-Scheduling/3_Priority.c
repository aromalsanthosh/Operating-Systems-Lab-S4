/* 
    Priority scheduling with different arrival time-nonpreemptive
*/

#include<stdio.h>
#include<stdlib.h>

struct process
{
    int pid;
    int bt;
    int at;
    int ct;
    int wt;
    int tat;
    int priority;
};

int main()
{
    int i,j,n,total_wt=0,total_tat=0;
    float avg_wt,avg_tat;

    printf("Enter total number of processes : ");
    scanf("%d",&n);
    struct process proc[n],temp;
    printf("Enter Process-id, Arrival-Time, Burst-time and Priority for each process\n");

    for(i=0; i<n; i++)
    {
        printf("Process %d : ",i+1);
        scanf("%d %d %d %d",&proc[i].pid,&proc[i].at,&proc[i].bt,&proc[i].priority);
    }

    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            //first sorting according to arrival time
            if(proc[i].at > proc[j].at)
            {
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
            //if arrival-time is same
            if(proc[i].at == proc[j].at)
            {
                //then sort according to priority
                if(proc[i].priority > proc[j].priority)
                {
                    temp = proc[i];
                    proc[i] = proc[j];
                    proc[j] = temp;
                }
                //if priority is also same
            }
            if(proc[i].at == proc[j].at && proc[i].priority == proc[j].priority)
            {
                if(proc[i].pid > proc[j].pid)
                {
                    temp = proc[i];
                    proc[i] = proc[j];
                    proc[j] = temp;
                }
            }

        }
    }

    proc[0].ct = (proc[0].bt+proc[0].at);
    for(i=1; i<n; i++)
    {
        proc[i].ct = proc[i-1].ct + proc[i].bt;
    }

    for(i=0; i<n; i++)
    {
        proc[i].tat = proc[i].ct - proc[i].at;
    }
    for(i=0; i<n; i++)
    {
        proc[i].wt = proc[i].tat - proc[i].bt;
    }

    // for(i=1; i<n; i++)
    // {
    //     proc[i].ct = proc[i-1].ct + proc[i].bt;
    //     proc[i].tat = proc[i].ct - proc[i].at;
    //     proc[i].wt = proc[i].tat - proc[i].bt;
    // }

    long int waiting_total=0,turn_around_total=0;

    for(i=0;i<n;i++)
    {
        waiting_total += proc[i].wt;
        turn_around_total += proc[i].tat;
    }

    float avg_waiting_time = (float)waiting_total/(float)n;

    float avg_turn_around_time = (float)turn_around_total/(float)n;

    //printf("Process\t\tarrival-time\t\tBurst time\t\tpriority\t\twaiting time\t\tTurn_around_time\n");


    printf("\n-----------------------------------------------------------------------------------------");
    printf("\nProcesses  Arrival Time    Burst Time   Priority  Waiting Time  Turn-Around Time");
    printf("\n-----------------------------------------------------------------------------------------");


    for(i=0; i<n; i++)
    {
        printf("\n%6d  %8d  %13d  %14d  %15d %15d",proc[i].pid,proc[i].at,proc[i].bt,proc[i].priority,proc[i].wt,proc[i].tat);
    }

    printf("\nAverage waiting time = %.3f\n",avg_waiting_time);

    printf("Average turn around time = %.3f\n",avg_turn_around_time);

    return 0;
  }