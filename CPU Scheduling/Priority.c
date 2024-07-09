//Priority CPU Scheduling

#include <stdio.h>

typedef struct Priority
{
	int PID;
	int bt;
	int tat;
	int wt;
	int pri; //Priority
}process;

int main()
{
	int n, total_tat = 0, total_wt = 0;
	printf("PRIORITY CPU SCHEDULING\n");
	printf("Lowest number has highest priority.\n");
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	process p[n], temp;
	
	//Accepting input from user
	printf("Enter PID, Burst Time and Priority:\n");
	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &p[i].PID, &p[i].bt, &p[i].pri);
	
	//Sorting on the basis of priority
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (p[j].pri > p[j + 1].pri)
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
	
	//Gantt Chart
	printf("Gantt Chart: ");
	for (int i = 0; i < n; i++)
	{
		p[i].tat = p[i - 1].tat + p[i].bt;
		printf("|P%d\t%d", p[i].PID, p[i].tat);
	}
	printf("|\n");
	
	//Turnaround time and Waiting time
	for (int i = 0; i < n; i++)
	{
		total_tat += p[i].tat;
		p[i].wt = p[i].tat - p[i].bt;
		total_wt += p[i].wt;
	}
	
	float avg_tat = (float)total_tat / n;
	float avg_wt = (float)total_wt / n;
	
	printf("Process ID\tBurstTime\tPriority\tTurnaround Time\tWaiting Time\n");
	for (int i = 0; i < n; i++)
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].PID, p[i].bt, p[i].pri, p[i].tat, p[i].wt);
	
	printf("Average Turnaround Time: %.2f\n", avg_tat);
	printf("Average Waiting Time: %.2f\n", avg_wt);
	
	return 0;
}
