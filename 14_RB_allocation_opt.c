#include<stdio.h>
#include<stdlib.h>

int main(){

    int nPRB, nSlots =0;

    int *RBgrid;

    printf("Enter the no.of PRBs = ");
    scanf("%d",&nPRB);
    printf("Enter the no.of Slots = ");
    scanf("%d",&nSlots);

    RBgrid = (int *)calloc(nSlots,sizeof(int));


    printf("sltIdx = %d\t",0);

    //print for 0th slot
    for(int rb=0;rb<nPRB;rb++){
        printf("%d,",RBgrid[rb]);

    }
    printf("\n");



    for(int sltIdx=1;sltIdx<nSlots;sltIdx++){

        printf("sltIdx = %d\t",sltIdx);

        for(int rbidx=0;rbidx<nPRB;rbidx++){

            if((rbidx % sltIdx)==0){

            RBgrid[rbidx] = !(RBgrid[rbidx]);

            }

        }
        
        for(int rb=0;rb<nPRB;rb++){

            printf("%d,",RBgrid[rb]);

        }
        printf("\n");
    }

    return 0;

}
