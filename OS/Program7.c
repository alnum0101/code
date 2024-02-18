#include <stdio.h>
#include <stdlib.h>

#define FRAME_SIZE 3
#define REFERENCE_STRING_SIZE 10

void fifo(int reference_string[], int size) {
    int frame[FRAME_SIZE];
    int frame_index = 0;
    int page_faults = 0;

    printf("\nFIFO Page Replacement Algorithm:\n");

    for (int i = 0; i < size; i++) {
        int page = reference_string[i];
        int page_found = 0;

        // Check if the page is already in the frame
        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frame[j] == page) {
                page_found = 1;
                break;
            }
        }

        if (!page_found) {
            // Page fault
            printf("Page %d caused a page fault.\n", page);

            if (frame_index < FRAME_SIZE) {
                // There is space in the frame
                frame[frame_index++] = page;
            } else {
                // Replace the oldest page in the frame
                for (int j = 0; j < FRAME_SIZE - 1; j++) {
                    frame[j] = frame[j + 1];
                }
                frame[FRAME_SIZE - 1] = page;
            }

            page_faults++;
        }

        // Display the current state of the frame
        printf("Frame: ");
        for (int j = 0; j < frame_index; j++) {
            printf("%d ", frame[j]);
        }

        printf("\n");
    }

    printf("Total Page Faults: %d\n", page_faults);
}

void lru(int reference_string[], int size) {
    int frame[FRAME_SIZE];
    int time_used[FRAME_SIZE];
    int page_faults = 0;

    printf("\nLRU Page Replacement Algorithm:\n");

    for (int i = 0; i < size; i++) {
        int page = reference_string[i];
        int page_found = 0;

        // Check if the page is already in the frame
        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frame[j] == page) {
                page_found = 1;
                time_used[j] = i; // Update time used
                break;
            }
        }

        if (!page_found) {
            // Page fault
            printf("Page %d caused a page fault.\n", page);

            if (i < FRAME_SIZE) {
                // There is space in the frame
                frame[i] = page;
                time_used[i] = i;
            } else {
                // Find the least recently used page in the frame
                int min_time_index = 0;
                for (int j = 1; j < FRAME_SIZE; j++) {
                    if (time_used[j] < time_used[min_time_index]) {
                        min_time_index = j;
                    }
                }

                // Replace the least recently used page
                frame[min_time_index] = page;
                time_used[min_time_index] = i;
            }

            page_faults++;
        }

        // Display the current state of the frame
        printf("Frame: ");
        for (int j = 0; j < FRAME_SIZE; j++) {
            printf("%d ", frame[j]);
        }

        printf("\n");
    }

    printf("Total Page Faults: %d\n", page_faults);
}

int main() {
    int reference_string[REFERENCE_STRING_SIZE] = {1, 2, 3, 4, 2, 1, 5, 6, 2, 1};
    
    fifo(reference_string, REFERENCE_STRING_SIZE);
    lru(reference_string, REFERENCE_STRING_SIZE);

    return 0;
}
