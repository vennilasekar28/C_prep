#include<stdio.h>

int main(){

    char fname[200];

    double a, b, c;

    printf("Enter the file name to be read\n");
    scanf("%s",fname);

    FILE *fp = fopen(fname,"r");

    while(fscanf(fp,"%lf\t%lf\t%lf\n",&a,&b,&c)==3){
        
        printf("%f\t%f\t%f\n",a,b,c);

    }


    return 0;
}