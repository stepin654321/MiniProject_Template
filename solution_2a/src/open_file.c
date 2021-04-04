#include "header.h"

error_handler fileOpen(char *fileaddr,char *mode, FILE **fptr){
    *fptr=fopen(fileaddr,mode);
    if(fptr==NULL){
        return FAIL;
    }
    else{
        return SUCCESS;
    }
}