#include <stdio.h>
#include <stdlib.h>

int random(int minN, int maxN){
        return minN + rand() % (maxN + 1 - minN);
}

void Q1(int arr[], int start, int end)
{
        printf("\nKo ai dc sinh ra:\n");
        for(int i = 0; i < end - start + 1; ++i)
                if(arr[i] == 2)
                        printf("%d  ", start + i);
}

void Q2(int arr[], int start, int end)
{
        printf("\n\nSo nguoi sinh ra <= 10: \n");
        for(int i = 0; i < end - start + 1; ++i)
                if(arr[i] <= 10)
                        printf("%d    ", start + i);

}

void Q3(int arr[], int start, int count_age)
{
        int count;
        for(int i = 0; i < count_age - start; i++)
                count += arr[i];
        printf("\n\nNguoi tren 50: %d", count);
}

int main(){
        int start = 1920, end = 1970, now = 1985;
        int age = 50;
        int arr[1000];
        int count_age = now - age;

        for(int i = 0; i < end - start + 1; i++)
                arr[i] = random(0, 20);

        Q1(arr, start, end);

        Q2(arr, start, end);

        Q3(arr, start, count_age);
}