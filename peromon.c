#include <stdio.h>
#include <math.h>
#include <stdlib.h>


typedef struct point_type_t{
  double x;
  double y;
  int passed;
} point_type;

#define LENGTH 5
point_type table[LENGTH];
int solution[LENGTH];


double distance(point_type a,point_type b){
  return sqrt(pow(a.x-b.x,2) +  pow(a.y-b.y,2));
}

void read_file(char* fname){
  FILE *fp;
  int i=0;
  double f1, f2;
  char xname[10],yname[10];

  if((fp = fopen( fname, "r" ))==NULL){
    printf( "Can't open %s\n", fname );
    exit(1);
  }
  fscanf( fp, "%[^,],%s",xname,yname);   //[^,] avoid reading ','  
  for(int i=0; i<LENGTH; i++) {
    table[i].passed=0;
    if((fscanf( fp, "%lf,%lf",&table[i].x, &table[i].y) ) == EOF){ 
      break;   //end of file
    }
  }

  fclose(fp);
}

void output_file(void){
  FILE *fp;
  char *fname = "solution1.csv";
  int i;

  if((fp = fopen(fname, "w")) == NULL){
    printf( "Can't open %s\n", fname );
    exit(1);
  }

  for(i = 0; i < LENGTH; i++){
    if(fprintf(fp, "%d\n",solution[i])<0){
      break; //failed to write
    }
  }
  fclose(fp);
}


int main(void){
  int i,index,pointer=0;//current pointer
  read_file("input_0.csv");
  
  double min;
  int passed_n =1;

  table[pointer].passed =1;
  solution[passed_n]=pointer;
  printf("%d\n", pointer);

  while(passed_n < LENGTH){
    min = 1000000000;

    for(i=0;i<LENGTH;i++){
      if(!(table[i].passed) && i!=pointer){
          double dist = distance(table[pointer],table[i]);
          //printf("%d %d %lf\n",pointer, i, dist);
          if( dist < min){
              min = dist;
              index = i;
          }
      }
    } 
    pointer = index; //move pointer
    table[index].passed = 1;
    solution[passed_n]=index;
    printf("%d\n",index);
    passed_n ++;
  }

  output_file();
  return 0;

}
