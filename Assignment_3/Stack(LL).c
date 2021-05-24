#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

typedef struct Stack
{
        int data;
        struct Stack *next;
}*node;

node top;

node CreatNode(int x){
        node temp;
        temp = (node)malloc(sizeof(node));
        temp->data = x;
        temp->next = NULL;
        return temp;
}

void Push(int x){
        node temp;
        temp = CreatNode(x);
        temp->next = top;
        top = temp;
}

bool isEmpty(){
        return top == NULL;
}

int Peek(){
        if(!isEmpty())
                return top->data;
}

void Pop(){
        node temp;
        if(top == NULL)
                printf("UnderFlow");
        else{
                temp = top;
                top = top->next;
                temp->next = NULL;
        }
}

void Display(){
        node temp;
        if(top == NULL)
                printf("UnderFlow");
        else{
                temp = top;
                while(temp != NULL){
                        printf("%d\n", temp->data);
                        temp = temp->next;
                }
        }
}

int main(){
        Push(1);
        Push(2);
        Push(3);
        Push(4);

        Display();

        Pop();
        Pop();

        printf("======== After Pop ========\n\n");
        Display();
        printf("\n======== Top = [%d] ========\n\n\n", Peek());
}