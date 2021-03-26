#include "header_file.h"
#include<stdio.h>
#include <string.h>

int retrieve(char* name)
{
    FILE* fptr = fopen(name,"r");
    if(!fptr) {
        printf("Can\'t open file \n");
    }
    else {
        char buffer[2048];
        int row = 0;
        int column = 0;

        while (fgets(buffer, 2048, fptr)){
            column = 0;
            row++;

            if (row == 1)
                continue;

            char* value = strtok(buffer,", ");

            while(value) {
                if (column == 0) {
                    printf("\n\nName : ");
                }

                if (column == 1) {
                    printf("\nEmail_Id : ");
                }
    
                if (column == 2) {
                    printf("\nGithub_Link : ");
                }

                printf("%s", value);
                value = strtok(NULL, ", ");
                column++;
            }  

            printf("\n");  
        }
        fclose(fptr);
    }

    return 0;  
}