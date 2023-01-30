#pragma once

// length of a time quantum
#define QUANTUM 10

#include <stdio.h>

#include "task.h"

// run the specified task for the following time slice
void run(Task *task, int slice);
