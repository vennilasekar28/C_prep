#include<stdio.h>

#define NPRB (20)
#define NumSlots (20)

int main(){

    int RBgrid[NumSlots][NPRB] = {{0}};


    //print the RBgrid for 0th slot

    printf("Slot 0:\t");
    for(int rbidx=0;rbidx<20; rbidx++){

        printf("%d\t",RBgrid[0][rbidx]);
    }

    printf("\n");

    //allocation
    for(int slotidx=1;slotidx<NumSlots;slotidx++){

        for(int rbidx=0;rbidx<NPRB; rbidx++){

            if((rbidx % slotidx)==0){
                RBgrid[slotidx][rbidx] = !RBgrid[slotidx-1][rbidx];
            }
            else{

                RBgrid[slotidx][rbidx] = RBgrid[slotidx-1][rbidx];   
            }
            
        }

    }
///*
    for(int slotidx=1;slotidx<20;slotidx++){

        printf("Slot %d:\t",slotidx);

        for(int rbidx=0;rbidx<20; rbidx++){

            printf("%d\t",RBgrid[slotidx][rbidx]);
        }

        printf("\n");

    }
        //*/


    return 0;
}

