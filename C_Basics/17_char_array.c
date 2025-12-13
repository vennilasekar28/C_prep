#include<stdio.h>
#include<stdlib.h>


int main(){

    char *name[5];

    char name_len = 50;
   
    for(int i=0;i<5;i++){

        name[i] = (char *)(malloc(name_len*sizeof(char)));

        printf("Enter the S%d name = ",i+1);

        scanf("%s",name[i]);
    }

    printf("The given student names are as \n");

    for(int i=0; i<5;i++){

        printf("S1-name = %s\n",name[i]);

        free(name[i]);
    }

    return 0;
}