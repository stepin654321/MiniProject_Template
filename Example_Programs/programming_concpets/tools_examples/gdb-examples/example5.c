/* *********** ORIGINAL CODE ****************** */

// #include<stdio.h>

// int mystrlen(const char* pstr);
// void test(char* pstr);

// int main(int argc, char* argv[]) {
//   int len=5;
//   char *pstable[5] = { "sunday", "monday", "tuesday"}; // no malloc
//   char *ps;
//   for(int i=0;i<len;i++)
//     test(pstable[i]);  
//   return 0;
// }
// void test(char* pstr) {
//   int len = mystrlen(pstr);
//   for(int j=0;j<len;j++)
//        if(pstr[j]=='e')
//           pstr[j] += 32;  // accessin memory without malloc
// }
// int mystrlen(const char* pstr) {
//   int k=0;
//   while(*pstr++) k++;
//   return k;
// }

/* **************Rectified Code***************** */


#include<stdio.h>

int mystrlen(const char* pstr);
void test(char* pstr);

int main(int argc, char* argv[]) {
  int len=5;
  //char *pstable[5] = { "sunday", "monday", "tuesday"};
  char **pstable = (char *)malloc(5*sizeof(char *));
  for(int i = 0; i<5 ; i++){
    pstable[i] = (char *)malloc(8);
  }
  
  pstable[0] = "sunday";
  pstable[1] = "monday";
  pstable[2] = "tuesday";
  char *ps;
  for(int i=0;i<len;i++)
    test(pstable[i]);  
  return 0;
}
void test(char* pstr_o){
  char *pstr = (char *)malloc(8);
  strcpy(pstr, pstr_o);
  int len = mystrlen(pstr);
  for(int j=0;j<len;j++){
       if(pstr[j]=='e')
          pstr[j] = 'a' + (pstr[j] - 'a' + 32) % 26;
  }
  pstr_o = pstr;
}
int mystrlen(const char* pstr) {
  int k=0;
  while(*pstr++) k++;
  return k;
}

