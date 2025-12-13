#include<stdio.h>
#include<math.h>

int main(){

    int num_REs = 0, num_REs2 = 0, prachRE = 139,N_SC_RB = 12,kappa = 2;

    num_REs = (prachRE + kappa);


    num_REs2 = ceil((double)num_REs / N_SC_RB);

    printf("Method-1 Ceiling using ceil function numREs = %d\n",num_REs2);


    num_REs2 = (num_REs + N_SC_RB -1)/ N_SC_RB;

    printf("Method-2 Ceiling wihtout ceil function numREs = %d\n",num_REs2);

    return 0;
}