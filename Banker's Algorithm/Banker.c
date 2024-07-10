//Banker's Algorithm for Deadlock Avoidance

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Banker
{
	int allocation[3];
	int max[3];
	int need[3];
	int done;
}process;

int main()
{
	int n, completed = 0, work[3], available[3];
	printf("Banker's Algorithm - Deadlock Avoidance\n");
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	process p[n];
	int seq[n];
	
	//Allocation
	printf("Enter allocations:\n");
	for (int i = 0; i < n; i++)
	{
		printf("Process %d: A B C\n", i);
		scanf("%d %d %d", &p[i].allocation[0], &p[i].allocation[1], &p[i].allocation[2]);
		p[i].done = 0;
	}
	printf("\n");
	
	//Maximum
	printf("Enter maximum:\n");
	for (int i = 0; i < n; i++)
	{
		printf("Process %d: A B C\n", i);
		scanf("%d %d %d", &p[i].max[0], &p[i].max[1], &p[i].max[2]);
	}
	printf("\n");
	
	//Available
	printf("Enter available:\n");
	printf("A B C\n");
	scanf("%d %d %d", &available[0], &available[1], &available[2]);
	printf("\n");
	
	//Need
	printf("Need:\n");
	printf("Process\t\tA\t\tB\t\tC\n");
	for (int i = 0; i < n; i++)
	{
		p[i].need[0] = p[i].max[0] - p[i].allocation[0];
		p[i].need[1] = p[i].max[1] - p[i].allocation[1];
		p[i].need[2] = p[i].max[2] - p[i].allocation[2];
		printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, p[i].need[0], p[i].need[1], p[i].need[2]);
	}
	printf("\n");
	
	//Safe sequence
	work[0] = available[0];
	work[1] = available[1];
	work[2] = available[2];
	while (completed < n)
	{
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			if (!p[i].done && (p[i].need[0] <= work[0]) && (p[i].need[1] <= work[1]) && (p[i].need[2] <= work[2]))
			{
				work[0] += p[i].allocation[0];
				work[1] += p[i].allocation[1];
				work[2] += p[i].allocation[2];
				p[i].done = 1;
				seq[completed++] = i;
				flag = true;
			}
		}
		if (!flag)
		{
			printf("No safe sequence\n");
			exit(0);
		}
	}
	
	printf("Safe sequence: ");
	for (int i = 0; i < n; i++)
		printf("%d\t", seq[i]);
	printf("\n");
	
	return 0;
}
