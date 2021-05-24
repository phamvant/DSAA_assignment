#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
        int data;
        struct Node *next;
        struct Node *prev;
}*node;

typedef struct
{
        node front, rear;
}*queue;

queue q;

node CreatNode(int x){
        node temp = (node)malloc(sizeof(node));
        temp->data = x;
        temp->next = NULL;
        temp->prev = NULL;
        return temp;
}

queue CreatQueue(){
        queue temp = (queue)malloc(sizeof(queue));
        temp->front = NULL;
        temp->rear = NULL;
        return temp;
}

bool isEmpty(){
        return q->front = NULL;
}

void enQueue(int x){
        node temp = CreatNode(x);
        if(q->rear == NULL){
                q->front = q->rear = temp;
                return;
        }
        temp->prev = q->rear;
        q->rear->next = temp;
        q->rear = temp;
}

void deQueue(){
        if(q->front == NULL)
                return;
        if(q->front == q->rear){
                q->rear = q->front = NULL;
        }else{
                node temp = q->front;
                q->front = q->front->next;
                q->front->prev = NULL;
        }
}

void display(){
        node temp = q->front;
        while(temp != NULL){
                printf(" %d", temp->data);
                temp = temp->next;
        }
}

int Front(){
        return q->front->data;
}

int main(){
        q = CreatQueue();
        enQueue(1);
        enQueue(2);
        enQueue(3);
        display();
        deQueue();
        printf("\n======= After deQueue ========\n");
        display();
        return 0;
}