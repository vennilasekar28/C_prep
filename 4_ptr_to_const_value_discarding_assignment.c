#include<stdio.h>

int main(){

    const int x = 5;
    int *p;

    p = &x;

    printf("The const integer value =%d\n",*p);

    *p = 10;
    printf("The const integer value =%d\n",x);
    return 0;
}