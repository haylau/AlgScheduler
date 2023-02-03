#pragma once

// length of a time quantum
#define QUANTUM 10
#define MAXALGS 25

#include <stdio.h>
#include <stdlib.h>

#include "task.h"

typedef struct cputime_t {
    char* name;
    int waitTime;
    int turnAroundTime;
    int responseTime;
    int lastExit;
} cputime_t;

// run the specified task for the following time slice
void run(Task* task, int slice);
void logTime(Task* task, int slice);
void stopCPU();
void printCPUUtil();
void printCPUTime();
