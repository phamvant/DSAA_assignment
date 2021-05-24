#include <stdio.h>

int tohop(int k, int n){
    if(k == 1)
        return n;
    if(k == 0 || k == n)
        return 1;
    return tohop(k - 1, n - 1) + tohop(k, n - 1);
}

int main(){
    printf("%d", tohop(3, 6));
}