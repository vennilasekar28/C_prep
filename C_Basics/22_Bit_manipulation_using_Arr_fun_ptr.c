#include<stdio.h>

typedef void (*nthBitPtr)(int, int);

typedef void (*kthBitPtr)(int, int, int);


void print_x_in_bin(int x){

    int bit;

    for(int i=31;i>=0;i--){

        bit = x&(1<<i);

        printf("%d",bit? 1 : 0);

    }

    printf("\n");
}



//set nth bit
void set_nth_bit_in_x(int x, int n){

    printf("The given number x = %d in binary = ",x);
    print_x_in_bin(x);

    x = x || (1<<(n-1));

    printf("After setting nth bit in x, the x = ");
    print_x_in_bin(x);

}


//reset nth bit
void reset_nth_bit_in_x(int x, int n){

    printf("The given number x = %d in binary = ",x);
    print_x_in_bin(x);

    x = x & (~(1<<(n-1)));

    printf("After resetting the nth bit in x, the x = ");
    print_x_in_bin(x);

}


//toggle nth bit
void toggle_nth_bit_in_x(int x, int n){
    printf("The given number x = %d in binary = ",x);
    print_x_in_bin(x);

    x = x ^ (1<<(n-1));

    printf("After toggling nth bit in x, the x = ");
    print_x_in_bin(x);

}

//set n bits from kth bit
//swap n, k position in given number x

int main(){

    void (*op[3])(int, int) = {set_nth_bit_in_x, reset_nth_bit_in_x, toggle_nth_bit_in_x}; 

    int x, n, task;

    
    printf("Enter the Bit-manipulation to be performed\n\ 
            0->set nth bit in x\n\
            1->reset nth bit in x\n\
            2->toggle nth bit in x\n");

    scanf("%d",&task);

    printf("\nEnter the x value x =");
    scanf("%d",&x);

    printf("\nEnter the nth bit value n =");
    scanf("%d",&n);

    printf("\noperation = %d\tx=%d\tn=%d\n",task,x,n);

    op[task](x,n);

    return 0;
}