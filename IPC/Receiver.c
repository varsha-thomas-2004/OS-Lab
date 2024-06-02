//Inter-Process Communication using Shared Memory

//Receiver
//Attach itself to the shared segment
//Read the value from Sender

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
	int shmid = shmget(1234, 1024, 0666 | IPC_CREAT);
	printf("Identifier of the shared segment is %d\n", shmid);
	void *shared_memory = shmat(shmid, NULL, 0);
	printf("Shared memory is attached to %p\n", shared_memory);
	printf("Data read from the shared memory:\n%s\n", (char *)shared_memory);
	return 0;
}
