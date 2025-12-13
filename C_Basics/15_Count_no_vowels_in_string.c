#include<stdio.h>
#include<string.h>

int main(){

    char name[200];
    int charcount = 0;
    
    printf("Enter the string to be printed name = ");
    scanf("%s",name);

    //Traverse the string
    for(int i=0;name[i]!='\0';i++){

        if((name[i]=='a')||(name[i]=='e')||(name[i]=='i')||(name[i]=='o')||(name[i]=='u')){
    

            charcount++;
        }


    }

    printf("The total vowel count in given char = %d\n",charcount);

    return 0;
}