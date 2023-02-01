/**
 * @file schedule.c
 * @author Hayden Lauritzen (haydenlauritzen@gmail.com)
 * @brief FCFS Scheduling
 * @date 2023-01-30
 *
 * @copyright Copyright (c) 2023
 *
 */


#include "../inc/schedulers.h"

#define TID_INIT 1

int tid_seq = TID_INIT;
struct node* g_head;
struct node* g_end;

// execute scheduled programs
void schedule() {
    printf("               [nm] [p] [b]\n");
    while (!isEmpty(g_head)) {
        Task* nextTask = pickNextTask();
        run(nextTask, nextTask->burst);
    }
}

// add to schedule list
void add(char* name, int priority, int burst) {
    // create a task
    ++tid_seq;
    Task* task = (Task*)malloc(sizeof(task));
    task->name = name;
    task->tid = tid_seq;
    task->priority = priority;
    task->burst= burst;
    // insert node
    if (g_head == NULL) {
        g_head = (struct node*)malloc(sizeof(struct node));
        g_head->task = task;
        g_end = g_head;
    }
    else {
        insert(&g_head, task);
    }
}

bool comesBefore(char* a, char* b) {
    return strcmp(a, b) < 0;
}

// finds the task whose name comes first in dictionary
Task* pickNextTask() {
    // if list is empty, nothing to do
    if (!g_head)
        return NULL;

    struct node* temp;
    temp = g_head;
    Task* best_sofar = temp->task;

    while (temp != NULL) {
        if (comesBefore(temp->task->name, best_sofar->name))
            best_sofar = temp->task;
        temp = temp->next;
    }
    // delete the node from list, Task will get deleted later
    delete (&g_head, best_sofar);
    return best_sofar;
}
