#include<stdio.h>

int main(){
    int val, bit;

    printf("Enter the number to be converted to Binary val = ");
    scanf("%d",&val);

    printf("\nThe Binary value is = ");
    for(int i=31; i>=0; i--){
        bit = val & (1<<i);
        
        printf("%d",bit ? 1:0);

    }

    printf("\n");

    return 0;

}


