#include <stdio.h>
#include <math.h>

typedef struct point_type_t{
  double x;
  double y;
  int passed;
} point_type;

#define LENGTH 5
point_type table[LENGTH];

double distance(double x1,double x2,double y1, double y2){
  return sqrt(pow(x1-x2,2) +  pow(y1-y2,2));
}

void read_file(char* fname){
  FILE *fp;
  int ret,i=0;
  double f1, f2;
  char xname[10],yname[10];

  if((fp = fopen( fname, "r" ))==NULL){
    printf( "Can't open %s\n", fname );
  }

  
    for(int i=0; i<LENGTH+1; i++) {
        if(i==0){
            fscanf( fp, "%[^,],%s",xname,yname);   //[^,] avoid reading ','
                }
        else{
            table[i-1].passed=1;
                if((ret = fscanf( fp, "%lf,%lf",&table[i-1].x, &table[i-1].y) ) != EOF){
                }
        }
       }
  fclose(fp);
}


int main(void){
  int i,index,pointer=0;
  read_file("input_0.csv");
  
  double min = 1000000000;

  int passed_n =0;//current pointer
  table[pointer].passed =0;
  printf("%d\n", pointer);

  while(passed_n < LENGTH-1){
    min = 1000000000;
    for(i=0;i<LENGTH;i++){
      if(table[i].passed && i!=pointer){
          double dist = distance(table[pointer].x,table[pointer].y,
			    table[i].x,table[i].y);
          //printf("%d %d %lf\n",pointer, i, dist);
          if( dist < min){
              min = dist;
              index = i;
          }
      }
    }
     
    table[index].passed = 0;
    pointer = index; //move pointer
    printf("%d\n",index);
    passed_n ++;
  }
  return 0;

}
