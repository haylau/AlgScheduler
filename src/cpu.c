/**
 * "Virtual" CPU that also maintains track of system time.
 */

#include "../inc/cpu.h"

float cpu_ticks = 0;
float cpu_sleep = 0;

cputime_t* alg_time[MAXALGS];

// run this task for the specified time slice
void run(Task* task, int slice) {
    printf("Running task = [%s] [%d] [%d] for %d units.\n", task->name, task->priority, task->remaining_time, slice);
    task->remaining_time -= slice;
    logTime(task, slice);
    printf("\tTime is now: %3.0f \n", cpu_ticks);
}

void logTime(Task* task, int slice) {
    // update cpu clock
    cpu_ticks += slice;
    ++cpu_sleep;

    // find process with 'name'
    int i = 0;
    while (alg_time[i] != NULL) {
        // found, process already started executing 
        if (strcmp(alg_time[i]->name, task->name) == 0) {
            // task was running
            if (task->remaining_time == 0) {
                // task exits
                alg_time[i]->endTime = cpu_ticks;
            }
            return;
        }
        ++i;
    }
    // process not in list, just starting executing
    alg_time[i] = (cputime_t*)malloc(sizeof(cputime_t));
    alg_time[i]->name = strdup(task->name);
    alg_time[i]->burst = task->burst;
    alg_time[i]->arrivalTime = 0; // can assume for this program
    alg_time[i]->beginTime = cpu_ticks - slice;
    alg_time[i]->endTime = 0;

    if (task->remaining_time <= 0) {
        // task exits
        alg_time[i]->endTime = cpu_ticks;
    }
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
        int turnAroundTime = alg_time[i]->endTime - alg_time[i]->arrivalTime;
        printf(" %d", turnAroundTime);
        if (turnAroundTime <= 9) printf(" ");
        if (turnAroundTime <= 99) printf(" ");
        printf("|");
    }
    printf("\n WT|");
    for (int i = 0; i < numAlgs; ++i) {
        int waitTime = alg_time[i]->endTime - alg_time[i]->arrivalTime - alg_time[i]->burst;
        printf(" %d", waitTime);
        if (waitTime <= 9) printf(" ");
        if (waitTime <= 99) printf(" ");
        printf("|");
    }
    printf("\n RT|");
    for (int i = 0; i < numAlgs; ++i) {
        int responseTime = alg_time[i]->beginTime - alg_time[i]->arrivalTime;
        printf(" %d", responseTime);
        if (responseTime <= 9) printf(" ");
        if (responseTime <= 99) printf(" ");
        printf("|");
    }
    printf("\n");
}

void emptyCPULog() {
    for (int i = 0; i < MAXALGS; ++i) {
        if (alg_time[i] != NULL) {
            free(alg_time[i]->name);
            free(alg_time[i]);
        }
    }
}