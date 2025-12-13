#include<stdio.h>

int main(){
    const int const *p;
  
    const int x=5;

    p = &x;

    printf("constant integer value pointed by contant pointer = %d\n",*p);

    //*p = 15;

   printf("constant integer value pointed by contant pointer = %d\n",x++);

    return 0;
}