#include<stdio.h>



typedef unsigned int uint32_t;
typedef char uint8_t;
typedef long int lint;
typedef long long int llint;
typedef long double ldouble;

//Structure padding inbetween the elements
typedef struct {
    uint8_t OccIdx;
    uint32_t TAval;
    double power;
}RACHParams1;

/*Structure padding inbetween the elements and 
end of the elements to make the total size is divisible by the maximum type of that structure memeber*/
typedef struct {
    uint8_t OccIdx;
    double power;
    uint32_t TAval;
}RACHParams2;

/* Largest size in the first order (or)
group the memebers together with same type */
typedef struct {
    double power;
    uint8_t OccIdx;
    uint32_t TAval;
}RACHParams3;

int main(){

    RACHParams1 RAParams1, *p1;
    p1 = &RAParams1;
    printf("size of RAParams1 is %lu\n",sizeof(RAParams1));

    RACHParams2 RAParams2, *p2;
    p2 = &RAParams2;
    printf("size of RAParams2 is %lu\n",sizeof(RAParams2));

    RACHParams3 RAParams3, *p3;
    p3 = &RAParams3;
    printf("size of RAParams3 is %lu\n",sizeof(RAParams3));

    printf("Address of [RAParams1][0] %p\n",&p1->OccIdx);
    printf("Address of [RAParams1][1] %p\n",&p1->TAval);
    printf("Address of [RAParams1][2] %p\n",&p1->power);


    return 0;
}
