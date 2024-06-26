//Disk Scheduling Algorithms
//SCAN

#include <stdio.h>
#include <stdlib.h>
#define MAX_REQUESTS 100

int main()
{
	int seekTime, total_seek_time = 0, n, requests[MAX_REQUESTS], currentTrack = 0, direction = 1;
	printf("SCAN Disk Scheduling\n");
	printf("Enter the number of requests: ");
	scanf("%d", &n);
	
	//Checking whether out of bounds
	if (n <= 0 || n > MAX_REQUESTS)
	{
		printf("Invalid input.\n");
		return 1;
	}
	
	//Request input
	printf("Enter requests:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &requests[i]);
	}
	
	//Calculating Seek Time
	for (int i = 0; i < n; i++)
	{
		while (currentTrack >= 0 && currentTrack <= 199)
		{
			if (currentTrack == requests[i])
			{
				seekTime += abs(currentTrack - requests[i]);
				requests[i] = -1;
				break;
			}
			currentTrack += direction;
			total_seek_time++;
		}
		
		//Change direction when required
		if (currentTrack == 200)
		{
			direction = -1;
			currentTrack = 199;
		}
		else if (currentTrack == -1)
		{
			direction = 1;
			currentTrack = 0;
		}
	}
	printf("Total seek time of SCAN is %d\n", total_seek_time);
	return 0;
}
