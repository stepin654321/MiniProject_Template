int main() {
  int i;
  double sum=0;
  for(i=1;i<=10;i++)
    if (i == 5){
      continue;
    }
    sum += 1.0 / (i-5); 
    /* i == 5, it will break used gcc -Wall -g exmaple1.c, 
    then kept a watch on sum, at i=5 it became inf without
     giving divide by 0 error, and format specifier for 
     float was worng.
    */
  printf("sum is %f\n",sum); 
  return 0;
}
