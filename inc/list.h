#pragma once

/**
 * list data structure containing the tasks in the system
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "task.h"

struct node {
    Task* task;
    struct node* next;
};

// insert and delete operations.
void insert(struct node** head, Task* task);
void append(struct node** tail, Task* task);
void delete(struct node** head, Task* task);
void traverse(struct node* head);
bool isEmpty(struct node* head);
