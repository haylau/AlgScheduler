/**
 * Driver.c
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/schedulers.h"

#define SIZE 100

int main(int argc, char* argv[])
{
    FILE* in;
    char* temp;
    char task[SIZE];

    char* name;
    int priority;
        int burst;

    if (argc <= 1) {
        printf("No processes provided.\n");
        return 1;
    }
    in = fopen(argv[1], "r");
    if (in == NULL) {
        printf("file %s failed to open\n", argv[1]);
        return 1;
    }

    while (fgets(task, SIZE, in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp, ",");
        priority = atoi(strsep(&temp, ","));
        burst = atoi(strsep(&temp, ","));

        // add the task to the scheduler's list of tasks
        add(name, priority, burst);

        free(temp);
    }

    fclose(in);

    // invoke the scheduler
    schedule();

    // print cpu data
    printCPUUtil();
    printCPUTime();

    // free cpu log memory
    emptyCPULog();

    return 0;
}
