#include<stdio.h>

int mystrlen(const char* pstr);
void test(char* pstr);

int main(int argc, char* argv[]) {
  int len=5;
  char *pstable[5] = { "sunday", "monday", "tuesday"};
  char *ps;
  for(int i=0;i<len;i++)
    test(pstable[i]);  
  return 0;
}
void test(char* pstr) {
  int len = mystrlen(pstr);
  for(int j=0;j<len;j++)
       if(pstr[j]=='e')
          pstr[j] += 32;  
}
int mystrlen(const char* pstr) {
  int k=0;
  while(*pstr++) k++;
  return k;
}
