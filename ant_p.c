#include<stdio.h>

double ALPHA = 1.0;
double BETA = 5.0;
double RHO = 0.5;
double Q = 100;

#define CITY_NUM 15
#define ANT_NUM 30

int MAX_ITER = 300

typedef struct point_type_t{
  double x;
  double y;
  int passed;
}point_type;

typedef struct fields_t{
  point_type *cities;
  double **dists;
  double **phers;
} fields;

typedef struct ant_t{
  int initial_city;
  int next_city;
  int cur_city;
  double tour_len;
  char* paths;
  fields f;
  double alpha;
  double beta;
} ant_t;

point_type table[CITY_NUM];
int solution[CITY_NUM];
double dists[CITY_NUM][CITY_NUM] = {0.0}; //Initialization
double phers[CITY_NUM][CITY_NUM] = {0.1}; //Initialization
ant ants[CITY_NUM];

void read_file(char* fname);
void output_file(void);
double distance(point_type a,point_type b);


void get_dists(void){
  double dist;
  for(int i=0;i<CITY_NUM;i++)
    for(int j=0;j<CITY_NUM;j++){
      dist = 0.0;
      if(i!=j){
	dits = distance(table[i],table[j]);
	dists[i][j] = dists[j][i] = dist;
      }
    }
}


void before_run(ant a){
  ants[i].next_city = -1;
  ants[i].cur_city = ants[i].initial_city;
  ants[i].tour_len = 0.0;
  ants[i].paths = "";
}


void run(ant a){
  before_run(a);
  available_cities[sizeof((a.f).cities)/sizeof(point_type)];
  // strcpy(availabel_cities,)
}

void get_ants(void){
    for(int i=0; i<CITY_NUM;i++){
      ants[i].initial_city = random;
      ants[i].f = fields;
      ants[i].alpha = ALPHA;
      ants[i].beta = BETA;
      before_run(ants[i]);
    }
}

void decay_pheromon(double pheromon){
  return (pheromon*(1.0 - RHO));
}
   
void delta_pheromon(double tour_len){
  return (Q/tour_len);
}

void update_pheromons(void){
  for(int i=0; i<CITY_NUM; i++){
    for(int j=0; j<CITY_NUM; j++){
      if(i!=j){
	pheromon = decay_pheromon(fields.phers[i][j]);
	fields.phers[i][j] = fields.phers[j][i] = pheromon;
      }
    }
  }

  for(int i=0; i<CITY_NUM; i++){
    for(int j=0; j<strlen(ants[i].paths); j++){
      int x = ants[i].paths[j];
      int t = ants[i].paths[j-1];
      double delta = delta_pheromon(ants[i].tour_len);
      fields.phers[f][t] += delta;
      fields.phers[f][t] = fields.phers[t][f];     
    }
  }
}

void start(void){
  ant best_ant = NULL;
  double min_len = INT_MAX;
  for(int i=0;i<MAX_ITER;i++){
    update_pheromons(fields,ants);
    for(int j=0;j<CITY_NUM;j++){
      run(ants[j]);
      if(ants[j].tour_len < min_len){
	best_ant = ants[j];
	min_len = ants[j].tour_len;
	printf("%lf\n",min_len);
      }
    }
  }
  return best_ant;
}


int main(void){
  read_file("input_1.csv"); //get cities
  get_dists(); //get distances
  get_ants();

  fields f = {table, dists, phers};

  ants = get_ants(ANT_NUM, fields);
  best_ant = start(fields, ants);
  //    print best_ant.paths
}




// ****************************************** //


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
