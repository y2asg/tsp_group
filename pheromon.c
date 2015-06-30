/*分泌量Δを決める関数*/
//引数として、そのアリｋちゃんが作った巡回経路の距離の総和ant.tour_lenをわたす。
//分泌量はもしアリkちゃんが通った辺にはQ÷距離を返す。通ってなかったら０を返す。、
void delta_pheromon(double ant.tour_len){
  int Q=100; /定数
  int delta=0;
  if(checkpath(int a , int b)==1){　//辺(a,b)が巡回経路の辺になっていたら
    delta=Q/ant.tour_len;
    return delta;
  }else{
    return 0;
  }
}
/*ありｋちゃんが巡回経路を作り終えるごとにフェロモンを更新するupdate_pheromon関数。蒸発率ρはどう設定するかは検討の必要あり*/
//何を引数とすればいいのかな

void update_pher(int now_pher){ //now_pheromon=t回の時のフェロモン蓄積量　new=t+1回目の蓄積量
  int new_pher=0;//next quantity of pheromon 次更新後のフェロモン蓄積量
  int delta=0;
  int RHO=0.8; //検討が必要
  delta=delta_pher(double ant.tour_len);//追加分泌量
  new_pher=RHO*now_pher+delta;//更新
  return new_pher;
}

