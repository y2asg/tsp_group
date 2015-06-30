
//まず、その辺がアリｋちゃんが通ったのか？を判別する関数 checkpath。もし通ってたら１を返す。通ってなかったら０を返す。
//引数は、地点aとb(a,b=頂点の名前（0 or 1 or 2 or …）)とそのときの巡回路の通った順番を表すant.solution[CITY_NUM]
//ant.solutiton[0]=0 で、かつ、ant.solution[CITY_NUM]（最後もう一度０）=0です

void checkpath(int a, int b, int ant.solution[CITY_NUM]){ //配列を引数に渡すやり方が未解決です
	int i=0;
	for(i=0;i<=CITY_NUM;i++){
		if(ant.solution[i]==a){
			order_a=i;
		}else{
			if(ant.solution[i]==b){
				order_b=i;
			}
		}else{
		}
	}
	if(order_a-order_b==1 || order_a-order_b==-1){
		return 1;
	}
	else{
		return 0;}
}
