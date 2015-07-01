
//まず、その辺がアリｋちゃんが通ったのか？を判別する関数 checkpath。もし通ってたら１を返す。通ってなかったら０を返す。
//引数は、地点aとb(a,b=頂点の名前（0 or 1 or 2 or …）)とそのときの巡回路の通った順番を表すant.solution[CITY_NUM]
//ant.solutiton[0]=0 で、かつ、ant.solution[CITY_NUM]（最後もう一度０）=0です

void checkpath(int city_a, int city_b, int*ant.solution){ //配列を引数に渡すやり方が未解決です
	int i=0;
	int ant.solution[CITY_NUM];
	for(i=0;i<=CITY_NUM;i++){ //頂点a,bは何番目に訪れたのかを調べる。
		if(ant.solution[i]==a){　//ant.solutionの配列の何番目にaを訪れたのか
			order_a=i; //a は　i番目でした
		}else{
			if(ant.solution[i]==b){////ant.solutionの配列の何番目にbを訪れたのか
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
