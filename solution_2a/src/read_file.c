#include "header.h"
#include<stdio.h>

int fileRead(FILE **fptr, char *buffer){
    return fscanf(*fptr,"%s",buffer);
}