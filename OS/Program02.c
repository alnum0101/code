#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findAverageTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n];
    findWaitingTime(processes, n, bt, wt);
    findTurnaroundTime(processes, n, bt, wt, tat);
    double total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }
    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}

void fcfs(int processes[], int n, int bt[]) {
    printf("\nFirst-Come-First-Serve (FCFS):\n");
    findAverageTime(processes, n, bt);
}

void sjf(int processes[], int n, int bt[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    printf("\nShortest Job First (SJF):\n");
    findAverageTime(processes, n, bt);
}

void roundRobin(int processes[], int n, int bt[], int quantum) {
    printf("\nRound Robin (RR) with quantum = %d:\n", quantum);
    int wt[n], tat[n];
    int remaining[n];
    for (int i = 0; i < n; i++) {
        remaining[i] = bt[i];
    }
    int t = 0; // Current time
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                done = 0; // There is a pending process
                if (remaining[i] > quantum) {
                    t += quantum;
                    remaining[i] -= quantum;
                } else {
                    t += remaining[i];
                    wt[i] = t - bt[i];
                    remaining[i] = 0;
                }
            }
        }
        if (done == 1) {
            break;
        }
    }
    findTurnaroundTime(processes, n, bt, wt, tat);
    double total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }
    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}

void priority(int processes[], int n, int bt[], int priority[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
                temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;
            }
        }
    }
    printf("\nPriority Scheduling:\n");
    findAverageTime(processes, n, bt);
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {6, 8, 10};
    int priority[] = {3, 1, 2};
    int quantum = 2;
    fcfs(processes, n, burst_time);
    sjf(processes, n, burst_time);
    roundRobin(processes, n, burst_time, quantum);
    priority(processes, n, burst_time, priority);
    return 0;
}
