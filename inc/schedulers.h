#pragma once

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

#include <stdbool.h>
#include <stdlib.h>

#include "task.h"
#include "list.h"
#include "cpu.h"

// invoke the scheduler
void schedule();

// add a task to the list 
void add(char* name, int priority, int burst);

// returns lexographical order for scheduling conflicts
bool comesBefore(char *a, char* b);

// selects next task depending on schedule form
Task* pickNextTask();