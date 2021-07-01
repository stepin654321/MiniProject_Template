 #include <iostream>
#include <cstdlib>
#include <cstdio>
#include<cstring>
typedef struct key_value
{
    char name[50];
    char email_id[50];
    char github_link[50];
}dict;
void printValues(dict values[]);