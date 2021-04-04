#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/**
 * @file header.h
 * @author Ayushi Agarwal -256145(ayushiag882@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __HEADER_H__
#define __HEADER_H___

/**
 * @brief Defined flags to get and handle errors
 * 
 */
typedef enum error_handler{
    FAIL = 1,
    SUCCESS = 0,
} error_handler;

/**
 * @brief Defining Structure Format
 * 
 */
typedef struct information {
    char name[1000];
    char email_id[1000];
    char git_link[1000];
} information;

/**
 * @brief File opening utility
 * 
 * @param fileaddr // file input
 * @param mode     // mode of file reading,writing,append,etc.
 * @param fptr     // storing file pointer
 * @return error_handler 
 */
error_handler fileOpen(char *fileaddr,char *mode, FILE **fptr);

/**
 * @brief File reading utility
 * 
 * @param fptr 
 * @param buffer // to store the file data line by line
 * @return int 
 */
int fileRead(FILE **fptr, char *buffer);

/**
 * @brief Memory freeing utility, to free up dynamically allocated space.
 * 
 * @param user 
 */
void freeMemory(information *user);


/**
 * @brief Sorting Utitlity
 * 
 * @param arr 
 */
void sort(information *arr);

#endif