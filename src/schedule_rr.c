/**
 * @file schedule.c
 * @author Hayden Lauritzen (haydenlauritzen@gmail.com)
 * @brief RR Scheduling
 * @date 2023-01-30
 *
 * @copyright Copyright (c) 2023
 *
 */


#include "../inc/schedulers.h"

#define TID_INIT 1

int tid_seq = TID_INIT;
struct node* g_head;
struct node* g_tail;

// execute scheduled programs
void schedule() {
    printf("               [nm] [p] [b]\n");
    while (!isEmpty(g_head)) {
        Task* nextTask = pickNextTask();
        run(nextTask, min(nextTask->remaining_time, QUANTUM));
        // if process still has runtime, add to end of list
        if (nextTask->remaining_time > 0) {
            append(&g_tail, nextTask);
        }
        else if (nextTask->remaining_time == 0) {
            free(nextTask->name);
            free(nextTask);
        }
    }
}

// add to schedule list
void add(char* name, int priority, int burst) {
    // create a task
    ++tid_seq;
    Task* task = (Task*)malloc(sizeof(Task));
    task->name = name;
    task->tid = tid_seq;
    task->priority = priority;
    task->burst = burst;
    task->remaining_time = burst;
    task->arrival_time = 0; // guarenteed for this program
    // insert node
    if (g_head == NULL) {
        g_head = (struct node*)calloc(1, sizeof(struct node));
        g_head->task = task;
        g_tail = g_head;
    }
    else {
        append(&g_tail, task);
    }
}

// finds the task whose name comes first in dictionary
Task* pickNextTask() {
    // if list is empty, nothing to do
    if (!g_head) return NULL;
    struct node* temp = g_head->next;
    Task* nextTask = g_head->task;
    // delete the node from list, Task will get deleted later
    delete (&g_head, nextTask);
    // move head pointer
    g_head = temp;
    return nextTask;
}
