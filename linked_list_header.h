#ifndef _LINKED_LIST_
#define _LINKED_LIST_
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    long data;
    struct Node *next;
}Node;
void print_ll(Node *head);
void push_back(Node** head, long new_data);
//Node* head1;
void freeNode();
void pop_front(Node **head_pp);
void push_front(Node ** head_pp, long new_data);
void pop_back(Node **head_pp);
#endif