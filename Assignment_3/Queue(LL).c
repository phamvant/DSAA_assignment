#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
        int data;
        struct Node *next;
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
                q->front = q->rear =temp;
                return;
        }
        q->rear->next = temp;
        q->rear = temp;
}

void deQueue(){
        if(q->front == NULL)
                return;
        node temp = q->front;
        q->front = q->front->next;
        if(q->front == NULL)
                q->rear = NULL;
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