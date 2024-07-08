//FCFS CPU Scheduling

#include <stdio.h>

typedef struct FCFS
{
	int PID;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
}process;

int main()
{
	int n, total_tat = 0, total_wt = 0;
	printf("FCFS CPU Scheduling\n");
	printf("Enter number of processes: ");
	scanf("%d", &n);
	process p[n], temp;
	
	//Accepting input from user
	printf("Enter PID, Arrival Time and Burst Time:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &p[i].PID, &p[i].at, &p[i].bt);
	}
	
	//Sorting according to arrival time
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (p[j].at > p[j + 1].at)
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
	
	//Gantt chart
	p[0].ct = p[0].bt + p[0].at;
	if (p[0].at == 0)
		printf("Gantt Chart: |P%d\t%d", p[0].PID, p[0].ct);
	else
		printf("Gantt Chart: |0\t%d|P%d\t%d", p[0].at, p[0].PID, p[0].ct);
	for (int i = 1; i < n; i++)
	{
		p[i].ct = p[i - 1].ct + p[i].bt;
		printf("|P%d\t%d", p[i].PID, p[i].ct);
	}
	printf("|\n");
	
	//Turnaround Time and Waiting Time
	for (int i = 0; i < n; i++)
	{
		p[i].tat = p[i].ct - p[i].at;
		total_tat += p[i].tat;
		p[i].wt = p[i].tat - p[i].bt;
		total_wt += p[i].wt;
	}
	float avg_tat = (float)total_tat / n;
	float avg_wt = (float)total_wt / n;
	
	printf("Average Turnaround Time: %.2f\n", avg_tat);
	printf("Average Waiting Time: %.2f\n", avg_wt);
	return 0;
}
