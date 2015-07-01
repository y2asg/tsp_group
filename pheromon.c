/*分泌量Δを決める関数*/
//引数として、そのアリｋちゃんが作った巡回経路の距離の総和ant.tour_lenをわたす。
//分泌量はもしアリkちゃんが通った辺にはQ÷距離を返す。通ってなかったら０を返す。、
void delta_pheromon(double ant.tour_len,city_a,city_b){
  checkpath(city_a,city_b);
  int Q=100; /定数
  int delta=0;
  if(checkpath(city_a,city_b)==1){　//辺(a,b)が巡回経路の辺になっていたら
    delta=Q/ant.tour_len;
    return delta;
  }else{
    return 0;
  }
}

/*ｔ回目からt+1回目のうちにフェロモンが蒸発するのを表す関数*/
void decay_pheromon(double pheromon){
    pheromon *= (1.0 - RHO);
    return pheromon
}


/*ありｋちゃんが巡回経路を作り終えるごとにフェロモンを更新するupdate_pheromon関数。蒸発率ρはどう設定するかは検討の必要あり*/
//a,b都市間の辺のフェロモンを更新させるように作ってある
//引数はテーブルfiels[i][j]が扱いやすいように都市a,bを渡す
void update_pher(int city_a, int city_b,double* fields , double ant.tour_len){
  double field=0;
  double pheromon=0;
  double new_fields[][]
  
  field = fields[city_a][city_b];
      new_pher=0://初期化
      if(city_a!=city_b){
                pheromon = decay_pheromon(field); //蒸発する
                delta=delta_pheromon(ant.tour_len);//追加分泌量
                new_pher=pheromon+delta;
                return new_pher;
      }else{
       0;  
      }
}
//メイン関数内でfieldsの更新を書く



