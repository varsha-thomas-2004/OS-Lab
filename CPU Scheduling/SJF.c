//CPU Scheduling Algorithms
//SJF - Shortest Job First
//Non Preemptive
//Arrival Time of sll processes taken as 0

#include <stdio.h>

typedef struct
{
	int name;
	int bt;
	int ct;
	int wt;
	int tat;
}process;

int main()
{
	int n, total_wt = 0, total_tat = 0;
	printf("SJF Scheduling (Non Preemptive)\n");
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	process p[n], temp;
	printf("Enter Process Name and Burst Time:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &p[i].name, &p[i].bt);
	}
	
	//Sort according to Burst Time
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (p[j].bt > p[j + 1].bt)
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
	
	//Gantt Chart
	p[0].ct = p[0].bt;
	printf("Gantt Chart: |P%d\t%d", p[0].name, p[0].ct);
	for (int i = 1; i < n; i++)
	{
		p[i].ct = p[i - 1].ct + p[i].bt;
		printf("|P%d\t%d", p[i].name, p[i].ct);
	}
	printf("|\n");
	
	
	//Turnaround Time and Waiting Time
	for (int i = 0; i < n; i++)
	{
		p[i].tat = p[i].ct;
		total_tat += p[i].tat;
		p[i].wt = p[i].tat - p[i].bt;
		total_wt += p[i].wt;
	}
	
	float avg_wt = (float)total_wt / n;
	float avg_tat = (float)total_tat / n;
	
	printf("Process Name\tBurst Time\tWaiting Time\tTurn Around Time\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d \t\t %d \t\t %d \t\t %d\n", p[i].name, p[i].bt, p[i].wt, p[i].tat);
	}
	
	printf("Average Waiting Time: %.2f\n", avg_wt);
	printf("Average Turn Around Time: %.2f\n", avg_tat);
	
	return 0;
}
