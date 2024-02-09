#include <stdio.h>
#include <stdlib.h>

int block_size[10], m, process_size[10], n, allocation[10], i, j;

void worstFit(int block_size[], int m, int process_size[], int n) {
    int allocation[n], i, j;

    for (i = 0; i < n; i++)
        allocation[i] = -1;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (block_size[j] >= process_size[i]) {
                allocation[i] = j;
                block_size[j] -= process_size[i];
                break;
            }
        }
    }


    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, process_size[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
}
}

void bestFit(int block_size[], int m, int process_size[], int n) {
    int allocation[n], i, j;

    for (i = 0; i < n; i++)
        allocation[i] = -1;

    for (i = 0; i < n; i++) {
        int bestIdx = -1;
        for (j = 0; j < m; j++) {
            if (block_size[j] >= process_size[i]) {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (block_size[bestIdx] > block_size[j])
                    bestIdx = j;
            }
        }

        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            block_size[bestIdx] -= process_size[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, process_size[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}


void firstFit(int block_size[], int m, int process_size[], int n) {
    int allocation[n], i, j;

    for (i = 0; i < n; i++)
        allocation[i] = -1;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (block_size[j] >= process_size[i]) {
                allocation[i] = j;
                block_size[j] -= process_size[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, process_size[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main()
{
    int d;
    printf("Enter the number of blocks: ");
    scanf("%d", &m);

    printf("Enter the size of each block:\n");
    for (i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &block_size[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the size of each process:\n");
    for (j = 0; j < n; j++) {
        printf("Process %d: ", j + 1);
        scanf("%d", &process_size[j]);
    }

    printf("\nEnter your choice:\n1. BEST FIT\n2. FIRST FIT\n3. WORST FIT\n");
    scanf("%d", &d);

    switch (d) {
        case 1:
            bestFit(block_size, m, process_size, n);
            break;
        case 2:
            firstFit(block_size, m, process_size, n);
            break;
        case 3:
            worstFit(block_size, m, process_size, n);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
