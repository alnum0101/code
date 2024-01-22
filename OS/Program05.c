#include <stdio.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int available[MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];

int request_resources(int process_id, int request[]);
int release_resources(int process_id, int release[]);
int is_safe_state();

int main() {
    // Initialize available resources
    printf("Enter the number of available resources:\n");
    for (int i = 0; i < MAX_RESOURCES; i++) {
        scanf("%d", &available[i]);
    }

    // Initialize maximum matrix
    printf("Enter the maximum demand matrix:\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            scanf("%d", &maximum[i][j]);
        }
    }

    // Initialize allocation matrix
    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            scanf("%d", &allocation[i][j]);
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    // Demonstrate resource request and release
    int process_id;
    int request[MAX_RESOURCES];
    int release[MAX_RESOURCES];
    
    printf("Enter the process ID (0 to %d):\n", MAX_PROCESSES - 1);
    scanf("%d", &process_id);

    printf("Enter the resource request:\n");
    for (int i = 0; i < MAX_RESOURCES; i++) {
        scanf("%d", &request[i]);
    }

    if (request_resources(process_id, request) == 1) {
        printf("Resource request granted. System is in a safe state.\n");

        printf("Enter the resources to release:\n");
        for (int i = 0; i < MAX_RESOURCES; i++) {
            scanf("%d", &release[i]);
        }

        release_resources(process_id, release);
    } else {
        printf("Resource request denied. System would be in an unsafe state.\n");
    }

    return 0;
}

int request_resources(int process_id, int request[]) {
    // Check if the request is within the need of the process
    for (int i = 0; i < MAX_RESOURCES; i++) {
        if (request[i] > need[process_id][i]) {
            return 0; // Request exceeds need
        }
    }

    // Check if the request is within the available resources
    for (int i = 0; i < MAX_RESOURCES; i++) {
        if (request[i] > available[i]) {
            return 0; // Insufficient resources
        }
    }

    // Try to allocate resources temporarily
    for (int i = 0; i < MAX_RESOURCES; i++) {
        available[i] -= request[i];
        allocation[process_id][i] += request[i];
        need[process_id][i] -= request[i];
    }

    // Check if the system is in a safe state
    if (is_safe_state()) {
        return 1; // Request granted
    } else {
        // Roll back changes if the system would be in an unsafe state
        for (int i = 0; i < MAX_RESOURCES; i++) {
            available[i] += request[i];
            allocation[process_id][i] -= request[i];
            need[process_id][i] += request[i];
        }
        return 0; // Request denied
    }
}

int release_resources(int process_id, int release[]) {
    // Release resources
    for (int i = 0; i < MAX_RESOURCES; i++) {
        available[i] += release[i];
        allocation[process_id][i] -= release[i];
        need[process_id][i] += release[i];
    }

    // Check if the system is in a safe state
    if (is_safe_state()) {
        printf("Resources released. System is in a safe state.\n");
        return 1; // Resources released
    } else {
        // Roll back changes if the system would be in an unsafe state
        for (int i = 0; i < MAX_RESOURCES; i++) {
            available[i] -= release[i];
            allocation[process_id][i] += release[i];
            need[process_id][i] -= release[i];
        }
        printf("Resources cannot be released. System would be in an unsafe state.\n");
        return 0; // Resources not released
    }
}

int is_safe_state() {
    int work[MAX_RESOURCES];
    int finish[MAX_PROCESSES];

    // Initialize work and finish arrays
    for (int i = 0; i < MAX_RESOURCES; i++) {
        work[i] = available[i];
    }
    for (int i = 0; i < MAX_PROCESSES; i++) {
        finish[i] = 0;
    }

    // Try to find an unmarked process that needs fewer resources than available
    int found;
    do {
        found = 0;
        for (int i = 0; i < MAX_PROCESSES; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < MAX_RESOURCES; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == MAX_RESOURCES) {
                    // Process i can finish
                    for (int k = 0; k < MAX_RESOURCES; k++) {
                        work[k] += allocation[i][k];
                    }
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
    } while (found);

    // Check if all processes are finished
    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (finish[i] == 0) {
            return 0; // System is in an unsafe state
        }
    }

    return 1; // System is in a safe state
}
