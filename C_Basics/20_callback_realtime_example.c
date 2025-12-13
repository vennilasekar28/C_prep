#include<stdio.h>

void schedulerCallback(int slot){
    printf("Scheduler triggered for slot %d\n", slot);
}

void phySlotProcessor(void (*cb)(int)){
    for(int slot=0; slot<4; slot++){
        printf("PHY processed slot %d\n", slot);
        cb(slot);   // callback !!
    }
}

int main(){
    phySlotProcessor(schedulerCallback);

    return 0;
}
