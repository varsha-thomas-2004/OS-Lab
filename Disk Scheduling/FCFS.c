//Disk Scheduling Algorithms
//FCFS - First Come First Serve

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int seekTime, total_seek_time = 0, currentTrack = 0, n;
	printf("FCFS Disk Scheduling\n");
	printf("Enter the number of requests: ");
	scanf("%d", &n);
	int requests[n];
	
	//Request input
	printf("Enter requests:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &requests[i]);
	}
	
	//Calculating Seek Time
	for (int i = 0; i < n; i++)
	{
		seekTime = abs(currentTrack - requests[i]);
		currentTrack = requests[i];
		total_seek_time += seekTime;
	}
	
	printf("Total seek time in FCFS is %d\n", total_seek_time);
	
	return 0;
}
