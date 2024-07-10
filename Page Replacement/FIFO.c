//FIFO Page Replacement Algorithm

#include <stdio.h>
#define MAX_FRAMES 3

int frames[MAX_FRAMES];
int rear = -1;

void initialize()
{
	for (int i = 0; i < MAX_FRAMES; i++)
		frames[i] = -1;
}

void Display()
{
	for (int i = 0; i < MAX_FRAMES; i++)
	{
		if (frames[i] != -1)
			printf("%d ", frames[i]);
		else
			printf("- ");
	}
	printf("\n");
}

int main()
{
	int n, exists, page;
	printf("FIFO Page Replacement Algorithm\n");
	printf("Enter the number of pages: ");
	scanf("%d", &n);
	int pages[n];
	
	printf("Enter the page reference sequence:\n");
	for (int i = 0; i < n; i++)
		scanf("%d", &pages[i]);
		
	initialize();
	
	int page_faults = 0;
	int front = 0;
	
	//FIFO
	for (int i = 0; i < n; i++)
	{
		exists = 0;
		page = pages[i];
		for (int j = 0; j < MAX_FRAMES; j++)
		{
			if (page == frames[j])
			{
				exists = 1;
				printf("Page %d already exists\n", page);
				break;
			}
		}
		
		if (!exists)
		{
			page_faults++;
			
			if (rear < MAX_FRAMES - 1)
				rear++;
			else
				rear = 0;
			frames[rear] = page;
			printf("Page %d loaded into frame %d\n", page, rear);
		}
		Display();
	}
	
	printf("Total number of page_faults: %d\n", page_faults);	
	
	return 0;
}
