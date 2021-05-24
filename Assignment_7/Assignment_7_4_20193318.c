#include <stdio.h>

int cmp(int a, int b){
  if (a > b)  
    return b;
  return a;
}

int min(int *a, int n)
{
  if (n == 2)
    return cmp(a[0], a[1]);
  return cmp(a[n - 1], min(a, n - 1));
}

int main()
{
  int a[] = {3,5,2,2,4,5,9};
  printf("%d", min(a, 6));
  return 0;
}