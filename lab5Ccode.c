#include <stdio.h>
#define arrsize 12
int sum;
int x;
char msg[]="done!\n";
int darr[arrsize];
int fsum(int arr[],int sz){
  int i;
  int rslt = 0;
  for(i = 0; i<=sz;i++){
    rslt = rslt + arr[i];
  }
  return rslt;
}

void main(){
  for(x = 1; x <=12;x++){
    darr[x] = x<<1;
  }

 sum = fsum(darr,arrsize);
  printf("sum = %d\n",sum);
  printf("%s\n",msg);
}
