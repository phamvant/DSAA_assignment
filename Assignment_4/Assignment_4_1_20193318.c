#include <stdlib.h>
#include <stdio.h>

typedef struct LinkedList
{
        int data;
        struct LinkedList *next;
        struct LinkedList *prev;
}*node;

node head, tail;

node CreatNode(int x){
        node temp;
        temp = (node)malloc(sizeof(node));
        temp->data = x;
        temp->next = NULL;
        temp->prev = NULL;
        return temp;
}

void InsertHead(int x){
        node temp = CreatNode(x);
        if(head == NULL){
                head = temp;
                tail = temp;
                return;
        }
        head->prev = temp;
        temp->next = head;
        head = temp;
        return;
}

void InsertTail(int x){
        node temp = CreatNode(x);
        if(head == NULL){
                head = temp;
                tail = temp;
                return;
        }
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
}

void DelHead(){
        if(head == NULL)
                return;
        head = head->next;
        head->prev = NULL;
}

void DelTail(){
        if(head == NULL)
                return;
        tail = tail->prev;
        tail->next = NULL;
}

void Traverse(){
        node temp = head;
        while(temp != NULL){
                printf("%d ", temp->data);
                temp = temp->next;
        }
        printf("\n");
}

void Traverse_Reverse(){
        node temp = tail;
        while(temp != NULL){
                printf("%d ", temp->data);
                temp = temp->prev;
        }
        printf("\n");
}

void main(){
        InsertHead(5);
        Traverse();
        InsertTail(6);
        Traverse();
        InsertTail(7);
        Traverse();
        InsertHead(4);
        Traverse();
        Traverse_Reverse();
        DelHead();
        Traverse();
        DelTail();
        Traverse();
}