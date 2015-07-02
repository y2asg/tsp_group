#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define LENGTH 16

typedef struct point_type_t{
  double x;
  double y;
  int passed;
} point_type;

double sum=100000000;
int num = 2;
point_type table[LENGTH];
int solution[LENGTH];


double distance(point_type a,point_type b){
  return sqrt(pow(a.x-b.x,2) +  pow(a.y-b.y,2));
}

void output(int lst[]){
  putchar('[');
  int i;
  for(i=0;i<LENGTH;i++){
    printf("%d ",lst[i]);
  }
  printf("]\n");
}

int apper(int lst[],int x,int n){
  int count=0;
  for(int i=0;i<n;i++){
    if(lst[i]==x) return 1;
  }
  return 0;
}

void append(int lst[], int x,int n){
  lst[n]=x;
}

double total_dist(int lst[]){
  double sum=0.0;
  for(int i=1;i<LENGTH;i++){
    sum += distance(table[lst[i-1]],table[lst[i]]);
  }
  return sum;
}

void copy_solution(int lst[]){
  for(int i=0;i<LENGTH;i++){
    solution[i] = lst[i];
  }
}

void perm_sub(int n,int lst[]){
  int i;
  if(n==LENGTH){
    double dist = total_dist(lst);
    if(dist<sum){
      sum = dist;
      copy_solution(lst);
    }
  }else{
    for(i=1;i<LENGTH;i++){
      if(!(apper(lst,i,num))){
	if(n!=2 || lst[0]>i){
	  append(lst,i,num);
	  num++;
	  perm_sub(n+1,lst);
	  num--;
	}
      }
    }
  }
}


void perm(m){
  int i;
  int ret[LENGTH+5] = {'\0'}; 
  for(i=1;i<LENGTH;i++){
    ret[0] = i;
    ret[1] = 0;
    perm_sub(2,ret);
  }
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
  read_file("input_2.csv");
 

  perm(LENGTH);
  output(solution);
  printf("dist = % lf\n",sum);
  output_file();
  return 0;

}
