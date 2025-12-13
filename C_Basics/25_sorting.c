#include<stdio.h>
#include<stdlib.h>


int main(){

    int *arr, n;

    printf("Enter the number of elements to be sorted\n");
    scanf("%d",&n);

    arr = (int *)(malloc(sizeof(int)*n));

    printf("Enter the elements\n");

    for(int i=0;i<n;i++){
       scanf("%d",&arr[i]);
    }

    int temp =0;

    for(int i=0; i<n;i++){

        for(int j=0;j<n-1-i;j++){

            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Sorted elements\n");

    for(int i=0;i<n;i++){
       printf("%d\t",arr[i]);
    }

    printf("\n");

    return 0;


}