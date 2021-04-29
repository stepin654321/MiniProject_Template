 /* function pointer */ //function pointer as arguments int ArithMaticOperation(int iData1,int iData2, pfunctPtr Calculation) { int iRet =0; iRet = Calculation(iData1,iData2); return iRet; } /*function add two number*/ int AddTwoNumber(int iData1,int iData2) { return (iData1 + iData2); } /*function subtract two number*/ int SubTwoNumber(int iData1,int iData2) { return (iData1 - iData2); } /*function multiply two number*/ int MulTwoNumber(int iData1,int iData2) { return (iData1 * iData2); } int main() { int iData1 = 10; int iData2 = 20; int iChoice = 1; int Result = 0; printf("Enter two Integer Data \n\n"); //scanf("%d%d",&iData1,&iData2); printf("Enter 1 for Addition \n\n"); printf("Enter 2 for Subtraction \n\n"); printf("Enter 3 for Multiplication \n\n"); printf("User choice :"); //scanf("%d",&iChoice); switch(iChoice)17:14
#include <stdio.h> 
typedef int (*pfunctPtr)(int, int);
{
case 1:
  Result = ArithMaticOperation(iData1, iData2, AddTwoNumber);
  break;
case 2:
  Result = ArithMaticOperation(iData1, iData2, SubTwoNumber);
  break;
case 3:
  Result = ArithMaticOperation(iData1, iData2, MulTwoNumber);
  break;
default:
  printf("Enter Wrong Choice\n\n");
}
printf("\n\nResult = %d\n\n", Result);
return 0;
}