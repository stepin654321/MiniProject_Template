#include<stdio.h>

int isVowel(char ch) {
  return ch=='a' || ch=='e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main(int argc, char* argv[]) {
  char *ps = "black";
  int len=strlen(ps);
  for(int i=0;i<len;i++)
     if(isVowel(ps[i]))
        ps[i] += 32;

  return 0;
}
