#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char sent[100],add[]="\"",with[]=",";
    char *ptr;
    printf("Enter Sentence with  '_' delimeter\n\n");
    gets(sent);
    printf("\n\n");
    ptr=strtok(sent,"_"); //split a string into a series of tokens based on a particular delimiter.

    while(ptr!=NULL)
     {
         printf("%s",add);
         printf("%s",ptr);
         printf("%s",add);
         ptr=strtok(NULL,"_");
         if(ptr!=NULL)
         {
             printf("%s",with);
         }
     }
     printf("\n\n");
}
