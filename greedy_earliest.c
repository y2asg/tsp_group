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
  char dammy[10];

  if((fp = fopen( fname, "r" ))==NULL){
    printf( "Can't open %s\n", fname );
    exit(1);
  }
  fscanf( fp, "%[^,],%s",dammy,dammy);   //[^,] avoid reading ','  
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
    fprintf(fp, "index\n");
  for(i = 0; i < LENGTH; i++){
    if(fprintf(fp, "%d\n",solution[i])<0){
      break; //failed to write
    }
  }
  fclose(fp);
}


int main(void){
  int i,index,pointer,j;//current pointer
  int presolution[LENGTH];
  read_file("input_0.csv");
  
  double min,t_dist,t_mindist=1000000000;
  int passed_n =1;
  for(j=0;j<LENGTH;j++){
      for (i=0; i<LENGTH; i++) {//initialize passsed
          table[i].passed =0;
      }
      passed_n=0;
      t_dist=0;
      pointer=j;
      table[pointer].passed =1;
      presolution[passed_n]=pointer;
 
      while(passed_n < LENGTH){
            min = 1000000000;
          
            for(i=0;i<LENGTH;i++){
                if(!(table[i].passed) && i!=pointer){
                    double dist = distance(table[pointer],table[i]);
                    if( dist < min){
                        min = dist;
                        index = i;
                    }
                }
            }
            if(passed_n != LENGTH-1){
            t_dist+=min;
            }
            pointer = index; //move pointer
            table[index].passed = 1;
            presolution[passed_n+1]=index;
            //printf("%d\n",index);
            passed_n ++;
        }
        t_dist+=distance(table[j],table[index]);
        if(t_dist<t_mindist){
            t_mindist=t_dist;
           for(i=0;i<LENGTH;i++){
                solution[i]=presolution[i];
            }
        }
    }
    for(i=0;i<LENGTH;i++){
        printf("%d\n",solution[i]);
    }

  //printf("%lf\n",t_mindist);
  
  output_file();
  return 0;

}
