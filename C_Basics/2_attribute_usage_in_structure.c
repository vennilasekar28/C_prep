#include<stdio.h>

int main()
{
    typedef struct example1{
        char a;
        int b;
    }without_align;

    without_align structure1;

    typedef struct example2{
        char a;
        int b;
    }__attribute__((packed)) with_align;

    with_align structure2 ;

    printf("sizeof without_align = %lu\n ",sizeof(structure1));
    printf("sizeof with_align = %lu\n ",sizeof(structure2));

    return 0;
}