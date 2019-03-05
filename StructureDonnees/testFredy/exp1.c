#include <stdio.h>
#include <stdlib.h>

//declaration des variable global
int numGLobal = 5;

//declaration de fonction
void positif(int num);

void main() {
  //declaration de variable local
  int numLocal = -10;
  positif(numGLobal);
  positif(numLocal);
}

//implementation des fonction
void positif(int num){
  if(num >= 0){
    printf("%d est positif \n", num);
  }else{
    printf("%d est negatif \n", num);
  }
}
