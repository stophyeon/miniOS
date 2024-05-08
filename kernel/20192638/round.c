#include <stdio.h>

#define MAX_PROCESS 5

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
} Process;


void roundRobinScheduling(Process processes[], int n, int quantum) {
    int i, currentTime = 0;

    for (i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time;
    }

    while (1) {
        int allFinished = 1;
        for (i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                allFinished = 0;
                if (processes[i].remaining_time <= quantum) {
                    currentTime += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    printf("프로세스 %d 완료됨 (실행 시간: %d)\n", processes[i].process_id, currentTime);
                } else {
                    currentTime += quantum;
                    processes[i].remaining_time -= quantum;
                    printf("프로세스 %d %d초 동안 실행됨\n", processes[i].process_id, quantum);
                }
            }
        }
        if (allFinished == 1)
            break;
    }
}