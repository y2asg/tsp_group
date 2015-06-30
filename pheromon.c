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
/*t回目からt+1回目更新*/
