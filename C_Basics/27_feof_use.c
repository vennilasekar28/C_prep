#include<stdio.h>

int main(){

    char filename[50];

    char string[60];

    sprintf(filename,"correlation_out_pwr.txt");

    FILE *fp = fopen(filename,"r");

    while(!feof(fp)){

        fgets(string,sizeof(string),fp);

        printf("%s\n",string);
    }

    return 0;
}