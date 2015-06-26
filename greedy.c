#include <stdio.h>
#include <math.h>

typedef struct point_type_t{
  double x;
  double y;
  int passed;
}point_type;

#define LENGTH 5
point_type table[LENGTH];

double distance(double x1,double x2,double y1, double y2){
  return sqrt((x1-x2)*(x1-x2) +  (y1-y2)*(y1-y2));
}

void read_file(char* fname){
  FILE *fp;
  int ret,i=0;
  double f1, f2;
  
  fp = fopen( fname, "r" );
  if(fp==NULL){
    printf( "%sファイルが開けません¥n", fname );
  }
  
  while( (ret = fscanf( fp, "%lf,%lf",&f1, &f2) ) != EOF){
    printf( "here");
    (table[i]).x = f1;
    (table[i]).y = f2;
    (table[i]).passed = 1;
    i++;
  }
  fclose(fp);
}


int main(void){
  printf( "here");
  int i,index,pointer=0;
  read_file("input_0.csv");
  
  double min = 1000000000;

  int passed_n =0;//現在のポインタ
  table[pointer].passed =0;


  while(passed_n < LENGTH){
    for(i=0;i<LENGTH;i++){
      if(table[i].passed && i!=pointer){
	int dist = distance(table[pointer].x,table[pointer].y,
			    table[i].x,table[i].y);
	if( dist < min){
	  min = dist;
	  index = i;
	}
      }
    }
    table[index].passed = 0;
    pointer = index; //ポインターを移動
    printf("%d\n",index);
    passed_n ++;
  }
  return 0;

}
