#include <stdio.h>
struct Process {
    int pid;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
};
void calculateWaitingTime(struct Process processes[], int n) {
    int totalWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        processes[i].waitingTime = totalWaitingTime;
        totalWaitingTime += processes[i].burstTime;
    }
}
void calculateTurnaroundTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].burstTime + processes[i].waitingTime;
    }
}
void printResults(struct Process processes[], int n) {
    float averageWaitingTime = 0.0;
    float averageTurnaroundTime = 0.0;
    printf("PID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burstTime, processes[i].arrivalTime, processes[i].waitingTime, processes[i].turnaroundTime);
        averageWaitingTime += processes[i].waitingTime;
        averageTurnaroundTime += processes[i].turnaroundTime;
    }
    averageWaitingTime /= n;
    averageTurnaroundTime /= n;
    printf("Average Waiting Time: %.2f\n", averageWaitingTime);
    printf("Average Turnaround Time: %.2f\n", averageTurnaroundTime);
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        printf("Enter the arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].burstTime > processes[j].burstTime) {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    calculateWaitingTime(processes, n);
    calculateTurnaroundTime(processes, n);
    printResults(processes, n);
    return 0;
}