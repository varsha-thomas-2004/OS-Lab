//Disk Scheduling Algorithms
//C-SCAN

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, seekTime, total_seek_time = 0, currentTrack = 0, requests[MAX_REQUESTS], temp, direction = 1;
	printf("C-SCAN Disk Scheduling\n");
	printf("Enter the number of requests: ");
	scanf("%d", &n);
	
	//Request Input
	printf("Enter requests:\n");
	for (int i = 0; i < n; i++)
		scanf("%d", &requests[i]);
	
	//Sort
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (requests[j] > requests[j + 1])
			{
				temp = requests[j];
				requests[j] = requests[j + 1];
				requests[j + 1] = temp;
			}
		}
	}
	
	//Calculating seek time
	for (int i = 0; i < n; i++)
	{
		while (currentTrack >= 0 && currentTrack <= 199)
		{
			if (currentTrack == requests[i])
			{
				requests[i] = -1;
				break;
			}
			currentTrack += direction;
			total_seek_time++;
		}
		if (currentTrack == 200)
		{
			direction = 1;
			currentTrack = 0;
		}		
	}
	printf("Total seek time of C-SCAN is %d\n", total_seek_time);
	return 0;
}
