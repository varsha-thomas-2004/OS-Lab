//LFU Page Replacement Algorithm

#include <stdio.h>
#define MAX_FRAMES 3

int frames[MAX_FRAMES];
int freq[MAX_FRAMES]; //frequency

void initialize()
{
	for (int i = 0; i < MAX_FRAMES; i++)
	{
		frames[i] = -1; //Not yet used frames
		freq[i] = 0;
	}
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

int findLFU()
{
	int min = freq[0];
	int lfu_frame = 0;
	for (int i = 1; i < MAX_FRAMES; i++)
	{
		if (min > freq[i])
		{
			min = freq[i]; //min gives the page with minimum frequency among all the existing frames.
			lfu_frame = i; //the frame with minimum frequency gets replaced.
		}
	}
	return lfu_frame;
}

int main()
{
	int n, exists, page, page_faults = 0;
	printf("LFU Page Replacement\n");
	printf("Enter the number of pages: ");
	scanf("%d", &n);
	int pages[n];
	
	printf("Enter page sequence:\n");
	for (int i = 0; i < n; i++)
		scanf("%d", &pages[i]);
	
	initialize();
	
	for (int i = 0; i < n; i++)
	{
		exists = 0;
		page = pages[i];
		for (int j = 0; j < MAX_FRAMES; j++)
		{
			if (page == frames[j])
			{
				exists = 1;
				freq[j]++; //since the page is encountered again in the sequence
				printf("Page %d already exists\n", page);
			}
		}
		if (!exists)
		{
			int lfu_frame = findLFU();
			printf("Page %d is loaded to frame %d\n",page, lfu_frame);
			frames[lfu_frame] = page;
			freq[lfu_frame] = 1; //first encounter in the sequence
			page_faults++;
		}
		Display();
	}
	
	printf("Total number of page faults: %d\n", page_faults);
	
	return 0;
}
