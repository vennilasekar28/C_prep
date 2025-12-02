#include<stdio.h>

int add(int x, int y){

    return x+y;
}

int mul(int x, int y){

    return x*y;
}

int compute(int event, int x, int y){

    int (*operation)(int, int);

    if((event % 2)==0){

        operation = add;

    }else{

        operation = mul;
        
    }

    return operation(x, y);

}

int main(){

    int event=4;

    int x=5, y=10, out;

    out = compute(event,x, y);

    printf("The function output is = %d\n", out);
    
    return 0;
}