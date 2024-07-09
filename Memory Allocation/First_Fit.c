//First Fit Memory Allocation

#include <stdio.h>

typedef struct First_Fit
{
	int size;
	int allocation;
	int stat; //Allocated or not
}process, memory;

int main()
{
	int blocks = 0, processes = 0;
	printf("FIRST FIT MEMORY ALLOCATION\n");
	
	//Blocks
	printf("Enter the number of blocks: ");
	scanf("%d", &blocks);
	memory b[blocks];
	printf("Enter the block sizes:\n");
	for (int i = 0; i < blocks; i++)
		scanf("%d", &b[i].size);
	
	//Processes
	printf("Enter the number of processes: ");
	scanf("%d", &processes);
	process p[processes];
	printf("Enter the sizes of processes:\n");
	for (int i = 0; i < processes; i++)
		scanf("%d", &p[i].size);
		
	//Memory Allocation
	for (int i = 0; i < processes; i++)
	{
		p[i].stat = 0;
		for (int j = 0; j < blocks; j++)
		{
			if (b[j].size >= p[i].size)
			{
				p[i].allocation = j;
				p[i].stat = 1;
				b[j].size -= p[i].size;
				break;
			}
		}
	}
	
	printf("Process\tProcess size\tStatus (1 - Allocated, 0 - Not allocated)\n");
	for (int i = 0; i < processes; i++)
		printf("%d\t\t%d\t\t%d\n", i + 1, p[i].size, p[i].stat);
	
	printf("Memory left:\n");
	for (int i = 0; i < blocks; i++)
		printf("%d\t", b[i].size);
	printf("\n");
	
	return 0;
}
