#include <stdio.h>
int arr[200][100]; 
void lab6(int *a,int rows,int cols){
	int i,j;
	for ( i = 0; i < rows;i++){
         for (j=0;j<cols;j++){
            a[i*cols+j] = rows * cols;
        }
       }
}
void main(){
  int i;
  for (i=0;i<10000;i++){ 
   lab6 (&arr[0][0],200,100);
  }
}

