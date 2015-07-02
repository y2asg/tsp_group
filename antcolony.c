#include <stdio.h>
#include <math.h>
#include <stdlib.h>


typedef struct point_type_t{
  double x;
  double y;
  int passed;
} point_type;

#define CITY_NUM 5
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

/*分泌量Δを決める関数*/
//引数として、そのアリｋちゃんが作った巡回経路の距離の総和ant.tour_lenをわたす。
//分泌量はもしアリkちゃんが通った辺にはQ÷距離を返す。通ってなかったら０を返す。、
void delta_pheromon(double tour_len, city_a, city_b){
  checkpath(city_a,city_b);
  int Q=100; /定数
  int delta=0;
  if(checkpath(city_a,city_b)==1){　//辺(a,b)が巡回経路の辺になっていたら
    delta=Q/tour_len;
    return delta;
  }else{
    return 0;
  }
}

/*ｔ回目からt+1回目のうちにフェロモンが蒸発するのを表す関数*/
void decay_pheromon(double pheromon){
    pheromon *= (1.0 - RHO);
    return pheromon;
}


/*ありｋちゃんが巡回経路を作り終えるごとにフェロモンを更新するupdate_pheromon関数。蒸発率ρはどう設定するかは検討の必要あり*/
//a,b都市間の辺のフェロモンを更新させるように作ってある
//引数はテーブルfielsd[i][j]が扱いやすいように都市a,bを渡す
void update_pher(int city_a, int city_b, double* fields , double tour_len){
  double field=0;
  double pheromon=0;
  field = fields[city_a][city_b];
      new_pher=0://初期化
      if(city_a!=city_b){
                pheromon = decay_pheromon(field); //蒸発する
                delta=delta_pheromon(tour_len);//追加分泌量
                new_pher=pheromon+delta;
                return new_pher;
      }else{
       return 0;  
      }
}

/*その辺がアリｋちゃんが通ったのか？を判別する関数 checkpath。もし通ってたら１を返す。通ってなかったら０を返す。*/
//引数は、地点aとb(a,b=頂点の名前（0 or 1 or 2 or …）)とそのときの巡回路の通った順番を表すant.solution[CITY_NUM]
//ant.solutiton[0]=0 で、かつ、ant.solution[CITY_NUM]（最後もう一度０）=0です

void checkpath(int city_a, int city_b, int *solution){ //配列を引数に渡すやり方が未解決です
	int i=0;
	int solution[CITY_NUM];
	for(i=0;i<=CITY_NUM;i++){ //頂点a,bは何番目に訪れたのかを調べる。
		if(solution[i]==a){　//ant.solutionの配列の何番目にaを訪れたのか
			order_a=i; //a は　i番目でした
		}else{
			if(solution[i]==b){//ant.solutionの配列の何番目にbを訪れたのか
				order_b=i;　//bはi番目
			}
		}else{
		}
	}
	if(order_a-order_b==1 || order_a-order_b==-1){　//もし経路が結ばれていたら、隣り合ってるはず。訪れた順番の差は１
		return 1;
	}
	else{
		return 0;}
}



void output_file(void){
  FILE *fp;
  char *fname = "solution1.csv";
  int i;

  if((fp = fopen(fname, "w")) == NULL){
    printf( "Can't open %s\n", fname );
    exit(1);
  }

  for(i = 0; i < CITY_NUM; i++){
    if(fprintf(fp, "%d\n",solution[i])<0){
      break; //failed to write
    }
  }
  fclose(fp);
}


int main(void){
  int i,index,pointer=0;//current pointer
  read_file("input_0.csv");
        double alpha=1.0; //constant number that means priotity for pheromon
	double beta=5.0;//that for huristics infomation
	double RHO=0.2; //pheromon no JOUHATURITU
	int Q=100; //constant number of pheromon
	int ANT_NUM = 30;// number of ant
	int solution[30][CITY_NUM] //すべてのアリの辿った道順を記憶する配列
	
  double min;
  int passed_n =1;
 

  table[pointer].passed =1;
  solution[passed_n]=pointer;
  printf("%d\n", pointer);

  while(passed_n < CITY_NUM){
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
