#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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

void Push(int k, Stack *S){
  if(!IsFull(*S)){
    S->info[S->n] = k;
    S->n++;
  }
}

bool Pop(Stack *S){
  if(!IsEmpty(*S)){
    S->n--;
    return true;
  }else
    return false;
}

int Top(Stack S){
  return S.info[S.n - 1];
}

void check(Stack *S, char* str){
  for(int i = 0; i < strlen(str); i++){
    if (str[i] == '('){
      Push(1, S);
    }else{
      if (Pop(S) == false){
        printf("Not balance");
        return;
      }
    }
  }
  printf("Balence");
  return;
}

int main(){
  Stack S;
  Creat(&S);
  char str[7] = "(())()";
  printf("Test string: %s\n", str);
  check(&S, str);
}