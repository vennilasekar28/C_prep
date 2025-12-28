#include<stdio.h>


int main(){

    int len;

    printf("Enter the array len\n");

    scanf("%d",&len);

    int arr[len];

    for(int i=0;i<len;i++){

        printf("Enter the value of  arr[i] =");
        scanf("%d",&arr[i]);
        printf("\n");

    }

    for(int i=0;i<len;i++){

        printf("arr[i] = %d\n",arr[i]);

    }


    return 0;
}