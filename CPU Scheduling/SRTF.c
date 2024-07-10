//SRTF CPU Scheduling

#include <stdio.h>
#include <stdbool.h>

typedef struct SRTF
{
	int PID;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	int rt; //remaining time
}process;

int main()
{
	int n, remain, current, total_tat = 0, total_wt = 0, time = 0, completed = 0;
	bool flag = true;
	printf("SRTF CPU Scheduling\n");
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	process p[n], temp;
	
	//Accepting input from user
	printf("Enter the PID, Arrival Time and Burst Time:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &p[i].PID, &p[i].at, &p[i].bt);
		p[i].rt = p[i].bt;		
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
	
	//SRTF
	while (completed < n)
	{
		current = -1;
		remain = __INT_MAX__;
		for (int i = 0; i < n; i++)
		{
			if (p[i].at <= time && p[i].rt > 0)
			{
				if (p[i].rt < remain)
				{
					remain = p[i].rt;
					current = i;	
				}
			}
		}
		if (current == -1)
			time++;
		else
		{				
			p[current].rt--;
			time++;
			if (p[current].rt == 0)
			{
				p[current].ct = time;
				completed++;
				p[current].tat = p[current].ct - p[current].at;
				total_tat += p[current].tat;
				p[current].wt = p[current].tat - p[current].bt;
				total_wt += p[current].wt;
			}
		}	
	}
	
	
	printf("Process ID\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].PID, p[i].at, p[i].bt, p[i].tat, p[i].wt);
	}
		
	float avg_tat = (float)total_tat / n;
	float avg_wt = (float)total_wt / n;

	printf("Average Turnaround Time: %.2f\n", avg_tat);
	printf("Average Waiting Time: %.2f\n", avg_wt);	
		
	return 0;
}
