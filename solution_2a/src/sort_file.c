  
#include "header.h"

int comparator(const void *user1,const void *user2){
    
    return strcmp(((information*)user1)->name,((information*)user2)->name);
  
}

void sort(information *arr){
    if(arr==NULL){
        return;
    }
    qsort(arr,5,sizeof(information),comparator);
}