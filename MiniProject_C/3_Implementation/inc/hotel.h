#ifndef HOTEL_H_INCLUDED
#define HOTEL_H_INCLUDED


#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>








void login();
void book();
void cancel();
void display();
int available(char name2[],int room,char status2[]);
int allot(char name1[],int type,char status1[]);
int getchoice();
int printroom(int choice);




#endif // HOTEL_H_INCLUDED
