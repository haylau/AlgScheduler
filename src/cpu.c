/**
 * "Virtual" CPU that also maintains track of system time.
 */

#include "../inc/cpu.h"

float cpu_ticks = 0;
float cpu_sleep = 0;

cputime_t* alg_time[MAXALGS];

// run this task for the specified time slice
void run(Task* task, int slice) {
    printf("Running task = [%s] [%d] [%d] for %d units.\n", task->name, task->priority, task->burst, slice);
    logTime(task, slice);
}

void logTime(Task* task, int slice) {
    cpu_ticks += slice;
    ++cpu_sleep;

    // find process with 'name'
    int i = 0;
    while (alg_time[i] != NULL) {
        // found, process already started executing
        if (alg_time[i]->name == task->name) {
            // task was running
            alg_time[i]->waitTime += (cpu_ticks - alg_time[i]->lastExit);
            if (slice >= task->burst) alg_time[i]->turnAroundTime = cpu_ticks;
            alg_time[i]->lastExit = cpu_ticks;
            return;
        }
        ++i;
    }
    // process not in list, just starting executing
    alg_time[i] = (cputime_t*)malloc(sizeof(cputime_t));
    alg_time[i]->name = task->name;
    alg_time[i]->waitTime = cpu_ticks - slice;
    alg_time[i]->turnAroundTime = (slice >= task->burst) ? cpu_ticks : 0;
    alg_time[i]->responseTime = cpu_ticks - slice;
    alg_time[i]->lastExit = cpu_ticks + slice;
}

void printCPUUtil() {
    printf("\nCPU Utilization: %%%2.2f\n", (100.0 * (cpu_ticks) / (cpu_ticks + cpu_sleep - 1)));
}

void printCPUTime() {
    int numAlgs = 0;
    while (alg_time[numAlgs] != NULL) ++numAlgs;

    printf("\n   |");
    for (int i = 0; i < numAlgs; ++i) {
        printf(" %s |", alg_time[i]->name);
    }
    printf("\n---|");
    for (int i = 0; i < numAlgs; ++i) {
        printf("----|");
    }
    printf("\nTAT|");
    for (int i = 0; i < numAlgs; ++i) {
        printf(" %d", alg_time[i]->turnAroundTime);
        if(alg_time[i]->turnAroundTime <= 9) printf(" ");
        if(alg_time[i]->turnAroundTime <= 99) printf(" ");
        printf("|");
    }
    printf("\n WT|");
    for (int i = 0; i < numAlgs; ++i) {
        printf(" %d", alg_time[i]->waitTime);
        if(alg_time[i]->waitTime <= 9) printf(" ");
        if(alg_time[i]->waitTime <= 99) printf(" ");
        printf("|");
    }
    printf("\n RT|");
    for (int i = 0; i < numAlgs; ++i) {
        printf(" %d", alg_time[i]->responseTime);
        if(alg_time[i]->responseTime <= 9) printf(" ");
        if(alg_time[i]->responseTime <= 99) printf(" ");
        printf("|");
    }

}

void stopCPU() {
    for(int i = 0; i < MAXALGS; ++i) {
        free(alg_time[i]);
    }
}