#pragma once

#ifndef max
#define max(a,b)             \
({                           \
    typeof (a) _a = (a);     \
    typeof (b) _b = (b);     \
    _a > _b ? _a : _b;       \
})
#endif // !max 

#ifndef min
#define min(a,b)             \
({                           \
    typeof (a) _a = (a);     \
    typeof (b) _b = (b);     \
    _a < _b ? _a : _b;       \
})
#endif // !min

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
bool comesBefore(char* a, char* b);

// selects next task depending on schedule form
Task* pickNextTask();