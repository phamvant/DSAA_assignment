#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

typedef struct{
  int *info;
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

void Push(Stack *S, char k){
  if(!IsFull(*S)){
    S->info[++S->n] = k;
  }
}

char Pop(Stack *S)
{
    if (!IsEmpty(*S))
        return S->info[S->n--] ;
    return '$';
}

int comp(char* equa, Stack *S)
{
    for (int i = 0; i < 8; i++)
    {
        if (isdigit(equa[i])){
            Push(S - '0', equa[i]);
        }
        else
        {
            int val1 = Pop(S);
            int val2 = Pop(S);
            printf("%d\n", val1);
            switch (equa[i])
            {
            case '+': Push(S, val2 + val1); break;
            case '-': Push(S, val2 - val1); break;
            case '*': Push(S, val2 * val1); break;
            case '/': Push(S, val2/val1); break;
            }
        }
    }
    return Pop(S);
}

int main(){
  Stack S;
  Creat(&S);
  char equa[8] = "532+-9*";
  printf("%d", comp(equa, &S));
}