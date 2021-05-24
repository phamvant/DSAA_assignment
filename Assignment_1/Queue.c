#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
    int info[MAX];
    unsigned int front;
    unsigned int rear;
}Queue;

void Creat(Queue *Q){
    Q->front = 0;
    Q->rear = 0;
}

bool IsFull(Queue Q){
    return (Q.rear == MAX);
}

bool IsEmpty(Queue Q){
    return (Q.front == Q.rear);
}

void Enqueue(Queue *Q, int value){
    if(IsFull(*Q))
        printf("Overflow\n");
    else{
        Q->info[Q->rear] = value;
        Q->rear += 1;
    }
}

void Dequeue(Queue *Q){
    if(IsEmpty(*Q))
        printf("Underflow");
    else{
        Q->info[Q->front] = 0;
        Q->front += 1;
    }
}

int Front(Queue Q){
    return(Q.info[Q.front]);
}

int main(){
    int n, value;
    Queue Q;
    Creat(&Q);
    do
    {
        printf("Nhap so phan tu can them: ");
        scanf("%d", &n);
    } while (n < 1);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        Enqueue(&Q, value);
    }
    
    printf("%d", Front(Q));
}