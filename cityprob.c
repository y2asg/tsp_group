#include<stdio.h>
#include<stdlib.h>

float p=0;
int w; //オメガ

float city_prob(float am, float* an){
  //*anは評価値の配列
  float sum;
  int i;
  for(i = 0; i<w; i++){
    sum = an[i];
  }
  
  p = (float)am/sum;
  
  return p;
}
