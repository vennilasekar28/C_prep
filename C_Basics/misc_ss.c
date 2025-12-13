#include <stdio.h>

#define NUM_PRB (273)
#define NUM_SLOT (273)

int alloc[NUM_PRB] = {0};

int main()
{
    for(int rb = 0; rb < NUM_PRB; rb++)
        alloc[rb] = 1;

    for(int slot = 2; slot < NUM_SLOT; slot++)
    {
        for(int rb = 0; rb < NUM_PRB; rb+=slot)
        {
            alloc[rb] = !alloc[rb];
        }
    }

    for(int rb = 0; rb < NUM_PRB; rb++)
    {
        printf("\n%d, %d", rb, alloc[rb]);
    }
    return 0;
}