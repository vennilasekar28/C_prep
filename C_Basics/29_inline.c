#include<stdio.h>

#define SQUARE(X) ((X)*(X))

static inline int square(int a){

    return a*a;
} 

int main(){

    int x = 5, out=0;

    out = SQUARE(x);

    printf("Macro out = %d\n",out);

    out = SQUARE(x++);

    printf("Macro out = %d\n",out);

    printf("x = %d\n",x);

    x = 5;

    out = square(x);
    printf("inline out = %d\n",out);

    out = square(x++);
    printf("inline out = %d\n",out);
    printf("x = %d\n",x);

    return 0;
}