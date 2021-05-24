#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
  int info[MAX];
  unsigned int n;
}Stack;

void Creat(Stack *S){
  S->n = 0;
}

bool IsEmpty(Stack S){
  if(S.n == 0)
    return true;
  return false;
}

bool IsFull(Stack S){
  if(S.n == MAX)
    return true;
  return false;
}

void Put(int k, Stack *S){
  if(!IsFull(*S)){
    S->info[S->n] = k;
    S->n++;
  }
}

void Pop(Stack *S){
  if(!IsEmpty(*S)){
    S->n--;
  }
}

int Top(Stack S){
  return S.info[S.n - 1];
}

int main(){
  Stack S;
  Creat(&S);
  int n;
  scanf("%d", &n);
  while(n){
    if(n % 2)
      Put(1, &S);
    else
      Put(0, &S);
    n /= 2;
  }
  while(!IsEmpty(S)){
    printf("%d", Top(S));
    Pop(&S);
  }
}