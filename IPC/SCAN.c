//*************************************************
// C Program Implementation-SCAN
//*************************************************
#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

// Function to calculate total seek time using SCAN algorithm
int calculateTotalSeekTime(int *requests, int numRequests) {
    int totalSeekTime = 0;
    int currentTrack = 0; // Start at track 0
    int direction = 1; // Initial direction: 1 (towards higher tracks)

    // Iterate through each request
    for (int i = 0; i < numRequests; i++) {
        // Scan in the current direction until the end of the disk
        while (currentTrack >= 0 && currentTrack <= 199) {
            // Check if the current request lies on the current track
            if (requests[i] == currentTrack) {
                totalSeekTime += abs(currentTrack - requests[i]); // Add seek time
                requests[i] = -1; // Mark request as serviced
                break; // Move to next request
            }
            // Move the disk arm in the current direction
            currentTrack += direction;
            totalSeekTime++; // Increment total seek time
        }

        // Change direction if necessary
        if (currentTrack == 200) {
            direction = -1; // Change direction to towards lower tracks
            currentTrack = 199; // Move to the highest track
        } else if (currentTrack == -1) {
            direction = 1; // Change direction to towards higher tracks
            currentTrack = 0; // Move to the lowest track
        }
    }

    return totalSeekTime;
}

int main() {
    int requests[MAX_REQUESTS];
    int numRequests;

    // Input number of disk requests
    printf("Enter the number of disk requests: ");
    scanf("%d", &numRequests);

    if (numRequests <= 0 || numRequests > MAX_REQUESTS) {
        printf("Invalid number of requests.\n");
        return 1;
    }

    // Input disk requests
    printf("Enter the disk requests (track numbers):\n");
    for (int i = 0; i < numRequests; i++) {
        scanf("%d", &requests[i]);
    }

    // Calculate and print total seek time
    int totalSeekTime = calculateTotalSeekTime(requests, numRequests);
    printf("Total seek time using SCAN: %d\n", totalSeekTime);

    return 0;
}
