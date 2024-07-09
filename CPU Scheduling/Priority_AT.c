//Priority CPU Scheduling

#include <stdio.h>

typedef struct Priority_AT
{
	int PID;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	int pri; //Priority
	int completed;
}process;

int main()
{
	int n, min, total_tat = 0, total_wt = 0, time = 0, completed = 0;
	printf("Priority CPU Scheduling\n");
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	process p[n], temp;
	
	//Accepting user input
	printf("Lower number has higher priority.\n");
	printf("Enter PID, Arrival Time, Burst Time and Priority:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &p[i].PID, &p[i].at, &p[i].bt, &p[i].pri);
		p[i].completed = 0;
	}
	
	//Sorting on the basis of arrival time
	for (int i = 0; i < n; i++)
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
	
	//Priority Scheduling
	printf("Gantt Chart: ");
	if (p[0].at != 0)
		printf("|0\t%d", p[0].at);
	while (completed < n)
	{
		min = -1;
		for (int i = 0; i < n; i++)
		{
			if (p[i].at <= time && p[i].completed == 0)
			{
				if (min == -1 || p[min].pri > p[i].pri)
					min = i;
			}
		}
		if (min != -1)
		{
			time += p[min].bt;
			p[min].ct = time;
			printf("|P%d\t%d", p[min].PID, p[min].ct);
			p[min].completed = 1;
			completed++;
			p[min].tat = p[min].ct - p[min].at;
			total_tat += p[min].tat;
			p[min].wt = p[min].tat - p[min].bt;
			total_wt += p[min].wt;
		}
		else
			time++;
	}
	printf("|\n");
	
	float avg_tat = (float)total_tat / n;
	float avg_wt = (float)total_wt / n;
	
	printf("Process ID\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\tPriority\n");
	for (int i = 0; i < n; i++)
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].PID, p[i].at, p[i].bt, p[i].tat, p[i].wt, p[i].pri);

	printf("Average Turnaround Time: %.2f\n", avg_tat);
	printf("Average Waiting Time: %.2f\n", avg_wt);
	
	return 0;
}
