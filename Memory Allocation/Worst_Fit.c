//Worst Fit Memory Allocation

#include <stdio.h>

typedef struct Worst_Fit
{
	int size;
	int allocation;
	int stat; //Status - Allocated or not
}process, memory;

int main()
{
	int max, blocks = 0, processes = 0;
	printf("WORST FIT MEMORY ALLOCATION\n");
	
	//Blocks
	printf("Enter the number of blocks: ");
	scanf("%d", &blocks);
	memory b[blocks];
	printf("Enter the sizes of blocks:\n");
	for (int i = 0; i < blocks; i++)
		scanf("%d", &b[i].size);
		
	//Processes
	printf("Enter the number of processes: ");
	scanf("%d", &processes);
	process p[processes];
	printf("Enter the sizes of processes:\n");
	for (int i = 0; i < processes; i++)
		scanf("%d", &p[i].size);
	
	//Memory allocation
	for (int i = 0; i < processes; i++)
	{
		max = -1;
		p[i].allocation = -1;
		p[i].stat = 0;
		for (int j = 0; j < blocks; j++)
		{
			if (b[j].size >= p[i].size)
			{
				if (max == -1 || b[max].size <= b[j].size)
					max = j;
			}
		}
		if (max != -1)
		{
			p[i].allocation = max + 1;
			p[i].stat = 1;
			b[max].size -= p[i].size;
		}
	}
	
	printf("Process\tProcess Size\tStatus (1 - Allocated, 0 - Not Allocated)\tAllocated Block\n");
	for (int i = 0; i < processes; i++)
		printf("%d\t\t%d\t\t%d\t\t\t\t\t%d\n", i + 1, p[i].size, p[i].stat, p[i].allocation);
	
	printf("Memory left:\n");
	for (int i = 0; i < blocks; i++)
		printf("%d\t", b[i].size);
	printf("\n");
	
	return 0;
}
