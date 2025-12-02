#include<stdio.h>

int main(){

    int arr[5] = {1, 2, 3, 4, 5};

    int (*p)[5];
    
    p = &arr;

    //Print all the values in array

    for(int i=0;i<5;i++){
        printf("arr[%d]=%d\n",i,(*p)[i]);
    }

    //change the 2nd element val
    (*p)[1] = 10;
    printf("Modified array val\n");
    for(int i=0;i<5;i++){
        printf("arr[%d]=%d\n",i,(*p)[i]);
    }

    return 0;
}