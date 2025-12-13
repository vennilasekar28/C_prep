#include<stdio.h>
#include<stdlib.h>

int main(){

    int *arr;

    int n;

    printf("enter the size of integer array n=");
    scanf("%d",&n);

    printf("\n");
    arr = malloc(n*sizeof(int));

    for(int i=0;i<n;i++){
        arr[i] = i+1;
        printf("arr[%d]=%d\n",i,arr[i]);

    }

    free(arr);

    return 0;
}