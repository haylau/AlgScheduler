/**
 * Various list operations
 */


#include "../inc/list.h"

 // add a new task to the list of tasks
void insert(struct node** head, Task* newTask) {
    if (head == NULL) return;
    // add the new task to the list 
    struct node* newNode = malloc(sizeof(struct node));
    // add node to front of list
    newNode->task = newTask;
    newNode->next = *head;
    *head = newNode;
}

// add a new task to the end of the list of tasks
void append(struct node** tail, Task* newTask) {
    if (tail == NULL) return;
    struct node* temp = *tail;
    // iterate to end
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // add the new task to the list 
    struct node* newNode = malloc(sizeof(struct node));
    // add node to end of list
    newNode->task = newTask;
    newNode->next = NULL;
    temp->next = newNode;
}

// delete the selected task from the list
void delete(struct node** head, Task* task) {
    struct node* temp;
    struct node* prev;

    temp = *head;
    // special case - beginning of list
    if (strcmp(task->name, temp->task->name) == 0) {
        *head = (*head)->next;
    }
    else {
        // interior or last element in the list
        prev = *head;
        temp = temp->next;
        while (strcmp(task->name, temp->task->name) != 0) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
    }
}

// traverse the list
void traverse(struct node* head) {
    struct node* temp;
    temp = head;

    while (temp != NULL) {
        printf("[%s] [%d] [%d]\n", temp->task->name, temp->task->priority, temp->task->burst);
        temp = temp->next;
    }
}

bool isEmpty(struct node* head) { return head == NULL; }