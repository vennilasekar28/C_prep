#include<stdio.h>
#include<stdlib.h>

int main(){
    int **arr,i,j, row, col;

    printf("Enter the number rows row = ");
    scanf("%d",&row);
    printf("\nEnter the number of columns col =");
    scanf("%d",&col);

    arr = malloc(row*sizeof(void *));

    for(i=0;i<row;i++){

        arr[i] = malloc(sizeof(int)*col);

        for(j=0;j<col;j++){

            arr[i][j] = i*col+j+1;
            printf("arr[%d][%d]=%d\n",i,j,arr[i][j]);

        }


    }

    for(i=0;i<row;i++){
        free(arr[i]);
    }

    free(arr);

    return 0;
}