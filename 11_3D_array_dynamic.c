#include<stdio.h>
#include<stdlib.h>

int main(){

    int block,row, col, h,i, j;
    int ***arr;

    printf("Enter the no.of block =");
    scanf("%d",&block);
    printf("\nEnter the no.of rows in each block =");
    scanf("%d",&row);
    printf("\nEnter the no.of columns in each row =");
    scanf("%d",&col);

    arr = malloc(block*sizeof(void *));

    for(h=0;h<block;h++){

        arr[h] = malloc(row*sizeof(void *));

        printf("Entering the elements of block[%d]\n",h);

        for(i=0;i<row;i++){

            arr[h][i] = malloc(col*sizeof(int));

            printf("Entering the elements of arr[%d]\n",i);


            for(j=0;j<col;j++){

                arr[h][i][j] = (h*row*col)+(i*(col))+j+1;
                printf("arr[%d][%d][%d] Add=%p\tval=%d\n",h,i,j,&arr[h][i][j],arr[h][i][j]);
            }


        }

    }

    for(h=0;h<block;h++){

        for(i=0;i<row;i++){

            free(arr[h][i]);
        }

        free(arr[h]);
    }

    return 0;
}