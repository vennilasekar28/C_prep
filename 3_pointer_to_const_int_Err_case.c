#include<stdio.h>

int main(){

    const int *p;
    int x = 5;

    p = &x;
    printf("The given constant integer value = %d\n",*p);

    //x = x+5;
    *p = x+5;

    printf("The modified constant integer value = %d\n",*p);

    return 0;

}