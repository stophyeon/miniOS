#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "system.h"
#define MAX_PROCESS 5

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
} Process;
void print_minios(char* str);

int main() {
    print_minios("[MiniOS SSU] Hello, World!");

    char *input;

    while(1) {
        // readline을 사용하여 입력 받기
        input = readline("커맨드를 입력하세요(종료:exit) : ");

        if (strcmp(input,"exit") == 0) {
            break;
        }

        if (strcmp(input,"minisystem") == 0){
            minisystem();
        }
	    if(strcmp(input,"jj")==0){
		    jj(); 
	    }
        if(strcmp(input,"ipc")==0){ipc();} 
        if (strcmp(input,"pi") == 0 )
        {
            cal();
        }
        if (strcmp(input, "process") ==0 )
        {
            Process processes[MAX_PROCESS] = {
            {1, 0, 8, 0},
            {2, 1, 4, 0},
            {3, 2, 9, 0},
            };

            int quantum = 2;

            printf("라운드 로빈 스케줄링을 시작합니다.\n");
             roundRobinScheduling(processes, MAX_PROCESS, quantum);

            return 0;
        }
        else system(input);
    }

    // 메모리 해제
    free(input);
    print_minios("[MiniOS SSU] MiniOS Shutdown........");

    return(1);
}

void print_minios(char* str) {
        printf("%s\n",str);
}
