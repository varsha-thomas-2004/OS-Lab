//Inter-Process Communication using Shared Memory

//Sender
//Creates shared segment
//Attaches to its address space
//Some content is written into it

//buffer - used for storing data temporarily
//shmid - returns the identifier of the shared segment, if failure occurs, returns -1
//shmat - returns the address to where the shared segment is attached


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
	char buffer[100];
	int shmid = shmget(1234, 1024, 0666 | IPC_CREAT); //key = 1234, size = 1024, permission = 0666 (Allowed to read and write, but not execute)  
	printf("Identifier of the shared segment is %d\n", shmid);
	void *shared_memory = shmat(shmid, NULL, 0);
	printf("Shared memory is attached to %p\n", shared_memory);
	printf("Enter data to be written into the shared segment:\n");
	read(0, buffer, 100);
	strcpy(shared_memory,buffer);
	printf("Data written: %s\n", (char *)shared_memory);
	return 0;
}
