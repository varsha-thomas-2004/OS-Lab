//LRU Page Replacement Algorithm

#include <stdio.h>
#define MAX_FRAMES 3

int frames[MAX_FRAMES];
int counter[MAX_FRAMES];

void initialize()
{
	for (int i = 0; i < MAX_FRAMES; i++)
	{
		frames[i] = -1; //Frame that is not used yet
		counter[i] = 0;
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

int findLRU()
{
	int max = counter[0];
	int lru_frame = 0;
	
	for (int i = 1; i < MAX_FRAMES; i++)
	{
		if (max < counter[i])
		{
			max = counter[i]; //max implies the time a particular page has taken in a given frame. The page that is not used for a long time gets replaced. The value in counter for the recently used page will be less.
			lru_frame = i;
		}
	}
	return lru_frame;
}

int main()
{
	int n, page, exists, page_faults = 0;
	printf("LRU Page Replacement Algorithm\n");
	printf("Enter the number of pages: ");
	scanf("%d", &n);
	int pages[n];
	
	printf("Enter the page sequence:\n");
	for (int i = 0; i < n; i++)
		scanf("%d", &pages[i]);

	initialize();
	
	for (int i = 0; i < n; i++)
	{
		page = pages[i];
		exists = 0;
		for (int j = 0; j < MAX_FRAMES; j++)
		{
			if (page == frames[j])
			{
				exists = 1; //recently used page
				printf("Page %d already exists\n", page);
				break;
			}
		}
		if (!exists)
		{
			int lru_frame = findLRU();
			printf("Page %d is loaded to frame %d\n", page, lru_frame);
			frames[lru_frame] = page; //new page added
			counter[lru_frame] = 0; //hence it's given the least time
			page_faults++;
		}
		for (int j = 0; j < MAX_FRAMES; j++)
				counter[j]++; //the unchanged pages' timer gets incremented
		for (int j = 0; j < MAX_FRAMES; j++)
		{
			if (frames[j] == page)
			{
				counter[j] = 0; //while the new page's as well as the recently used page's time is kept the same.
				break;
			}
		}
		Display();
	}
	
	printf("Total number of page faults: %d\n", page_faults);
	
	return 0;	
}
