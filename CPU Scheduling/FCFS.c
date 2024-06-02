//CPU Scheduling Algorithms
//FCFS - First Come, First Serve

#include <stdio.h>

typedef struct
{
	int name;
	int at;
	int bt;
	int wt;
	int ct;
	int tat;
}process;

int main()
{
	int n, total_wt = 0, total_tat = 0;
	
	printf("FCFS Scheduling\n");
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	process p[n];
	
	printf("Enter Process Name, Arrival Time, Burst Time:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &p[i].name, &p[i].at, &p[i].bt);
	}
	
	//Completion time
	p[0].ct = p[0].bt;
	for (int i = 1; i < n; i++)
	{
		p[i].ct = p[i - 1].ct + p[i].bt;
	}
	
	//Turn Around Time, Waiting Time
	for (int i = 0; i < n; i++)
	{
		p[i].tat = p[i].ct - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
	}
	
	//Total Turn Around Time & Waiting Time
	for (int i = 0; i < n; i++)
	{
		total_tat += p[i].tat;
		total_wt += p[i].wt;
	}
	float avg_wt = (float)total_wt/n;
	float avg_tat = (float)total_tat/n;
	
	printf("Name\tArrival Time\tBurst Time\tWaiting Time\tTurn Around Time\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d \t\t %d \t\t %d \t\t %d \t\t %d \n", p[i].name, p[i].at, p[i].bt, p[i].wt, p[i].tat);
	}
	printf("Average Waiting Time: %.2f\n", avg_wt);
	printf("Average Turn Around Time: %.2f\n", avg_tat);
	
	return 0;
}
