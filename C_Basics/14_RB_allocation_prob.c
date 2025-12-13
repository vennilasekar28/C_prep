#include<stdio.h>
#include<stdlib.h>

int main(){

    int nPRB, nSlots =0;

    int **RBgrid;

    printf("Enter the no.of PRBs = ");
    scanf("%d",&nPRB);
    printf("Enter the no.of Slots = ");
    scanf("%d",&nSlots);

    RBgrid = (int **)calloc(nSlots,sizeof(int *));

    //RB allocation
    for(int i=0;i<nSlots;i++){

        RBgrid[i] = (int *)calloc(nPRB, sizeof(int));

    }

    printf("sltIdx = %d\t",0);

    //print for 0th slot
    for(int rb=0;rb<nPRB;rb++){
        printf("%d,",RBgrid[0][rb]);

    }
    printf("\n");



    for(int sltIdx=1;sltIdx<nSlots;sltIdx++){

        printf("sltIdx = %d\t",sltIdx);

        for(int rbidx=0;rbidx<nPRB;rbidx++){

            printf("rb = %d,",rbidx);

            if((rbidx % sltIdx)==0){

            RBgrid[sltIdx][rbidx] = !(RBgrid[sltIdx-1][rbidx]);

            }else{

                RBgrid[sltIdx][rbidx] = (RBgrid[sltIdx-1][rbidx]);

            }

        }
        printf("\n");
        for(int rb=0;rb<nPRB;rb++){

            printf("%d,",RBgrid[sltIdx][rb]);

        }
        printf("\n");
    }

    return 0;

}
