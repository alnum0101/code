#include <stdio.h>
#include <stdlib.h>

// Function to sort the array of disk requests
void sortRequests(int requests[], int num_requests) {
    for (int i = 0; i < num_requests - 1; i++) {
        for (int j = 0; j < num_requests - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                // Swap requests[j] and requests[j+1]
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }
}

// Function to simulate the SCAN disk scheduling algorithm
void scan(int requests[], int num_requests, int start_position, int direction) {
    // Sort the requests
    sortRequests(requests, num_requests);
    int head_position = start_position;
    int total_head_movement = 0;

    // Find the index of the head position in the sorted requests
    int head_index;
    for (head_index = 0; head_index < num_requests; head_index++) {
        if (requests[head_index] >= head_position) {
            break;
        }
    }

    printf("Sequence of disk requests using SCAN algorithm:\n");

    // Scan towards the end
    for (int i = head_index; i < num_requests; i++) {
        printf("%d ", requests[i]);
        total_head_movement += abs(requests[i] - head_position);
        head_position = requests[i];
    }

    // If direction is left, move to the end of the disk
    if (direction == -1) {
        printf("0 ");
        total_head_movement += head_position;
        head_position = 0;
    }

    // Scan towards the beginning
    for (int i = head_index - 1; i >= 0; i--) {
        printf("%d ", requests[i]);
        total_head_movement += abs(requests[i] - head_position);
        head_position = requests[i];
    }

    printf("\nTotal head movement: %d\n", total_head_movement);
}

int main() {
    int num_requests;

    printf("Enter the number of disk requests: ");
    scanf("%d", &num_requests);

    int requests[num_requests];

    printf("Enter the disk requests:\n");
    for (int i = 0; i < num_requests; i++) {
        scanf("%d", &requests[i]);
    }

    int start_position;
    printf("Enter the starting head position: ");
    scanf("%d", &start_position);

    int direction;
    printf("Enter the direction (1 for right, -1 for left): ");
    scanf("%d", &direction);

    scan(requests, num_requests, start_position, direction);

    return 0;
}
