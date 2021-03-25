#include<stdio.h>
#include<string.h>

int isVowel(char ch) {
  return ch=='a' || ch=='e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main(int argc, char* argv[]) {
  char str[6] = "abcde"; 
  char *ps = (char *)malloc(6*sizeof(char)); 
  strcpy(ps,str);
  int len=strlen(ps);
  for(int i=0;i<len;i++){
    if(isVowel(ps[i])){
        ps[i] = 'a' + (ps[i] - 'a' + 32) % 26;
      }
    printf("%c", ps[i]);
  }
  free(ps);
  return 0;
}

/* 
  1. We cannot accesss memory on heap without allocating it with malloc -- fixed
  2. when adding 32 to vowels, non char values is being stored in 'ps', did some change in logic.
*/
