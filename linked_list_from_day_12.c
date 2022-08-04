#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    long data;
    struct Node *next;
}Node;
//Така като подаваме Node *head подаваме освен първия елемент, но реално подаваме целия списък
void print_ll(Node *head){ // Как да си принтираме листове, без да пишем много пъти printf
    Node *curNode = head;
    do
    {
        printf("addr: %p, data: %ld, next:%p\n",&head, head->data, &head->next);
        head = head->next;
    }while(head->next);
    printf("addr: %p, data: %ld, next:%p\n",&head, head->data, &head->next);
}
void push_back(Node** head, long new_data)//Така си добавяме нови елементи към списъка
{
    Node *new_node = malloc(sizeof(Node));
    if(!new_node){//Проверяваме дали имаме достатъчно памет да създадем нов елемент към листа
        perror("Push back: Could not malloc\n");
        exit(-1);
    }
    new_node->data = new_data;
    new_node->next = NULL;
    if((*head) == NULL){//Така ако свързания списък е имал нула елемента, тогава направо караме new_node = head
        *head = new_node;
        return;
    }
    Node *last_node;
    last_node = *head;
    while(last_node->next)
    {
        last_node = last_node->next;
    }
    last_node->next = new_node; //Обаче сега трябва да да правим фунцкия за освобождаване на паметта
}
Node* head1;
void freeNode(){
    Node *temp_Node;
    do
    {
        temp_Node = head1;
        head1 = head1->next;
        free(temp_Node);
    }while(head1->next);
    free(head1);
}

void pop_front(Node **head_pp){//Така го правим без глобален Node.
    if(!(*head_pp))//Така предотвратяваме да трием празен лист.
    {
        perror:("Pop front: Linked list is empty\n");
        return ;
    }
    Node *deleted_node = *head_pp;
    *head_pp = (*head_pp)->next;
    free(deleted_node);
}

void push_front(Node ** head_pp, long new_data){ // Creating new node infront
    Node* new_node = malloc(sizeof(Node));
    if(!new_node)
    {
        perror("Malloc error\n");
        exit(-1);
    }
    new_node->data = new_data;
    new_node->next = *head_pp;
    *head_pp = new_node;
}
void pop_back(Node **head_pp){
    if(*head_pp == NULL)
    {
        perror("LInked list is empty.");
        exit(-1);
    }
    Node* second_to_last_node, *last_node;
    last_node = *head_pp;
    while(last_node->next != NULL)
    {
        second_to_last_node = last_node;
        last_node = last_node->next;
    }
    if(last_node != *head_pp)
    {
        second_to_last_node->next = NULL;
    }
    else
    {
        *head_pp = NULL;
    }
    free(last_node);
}
int main()
{
    Node* head_linked_list_1 = NULL;
    push_back(&head_linked_list_1, 100);
    push_back(&head_linked_list_1, 200);
    push_back(&head_linked_list_1, 300);
    push_front(&head_linked_list_1, 1);
    push_front(&head_linked_list_1, 2);
    pop_back(&head_linked_list_1);
    print_ll(head_linked_list_1);

    return 0;
}
