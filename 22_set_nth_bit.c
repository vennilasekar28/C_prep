#include<stdio.h>


int main(){

    int x, n = 0;

    printf("Enter the given x value =");
    scanf("%d",&x);

    printf("Enter the nth position to be set n =");
    scanf("%d",&n);


    x = x|(1<<(n-1));

    printf("x=%d\n",x);

    return 0;
}