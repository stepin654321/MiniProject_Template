int main() {
  int i;
  double sum=0;
  for(i=1;i<=10;i++)
    sum += 1.0 / (i-5);
  printf("sum is %d\n",sum);
  return 0;
}
