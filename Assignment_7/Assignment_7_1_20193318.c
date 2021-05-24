#include <stdio.h>

int comp(int n){
    if (n == 1)
        return 1;
    return n + comp(n - 1);
}

int main(){
    printf("%d", comp(6));
}