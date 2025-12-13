#include<stdio.h>

int add(int x, int y){

    return x+y;
}

int main(){

    int x = 5, y=10, out=0;

    int (*fp)(int, int);

    fp = add;

    out = fp(x, y);

    printf("The out is = %d\n",out);

    return 0;
}