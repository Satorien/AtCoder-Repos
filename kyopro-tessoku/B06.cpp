/*
問題文
太郎君はくじを N 回引き，i 回目の結果は A i でした．
A i =1 のときアタリ，A i =0 のときハズレを意味します． 
「L 回目から R 回目までの中では，アタリとハズレどちらが多いか？」
という形式の質問が Q 個与えられるので， それぞれの質問に答えるプログラムを作成してください．

制約
1≤N,Q≤10^5
0≤A i ≤1
1≤L i ≤R i ≤N
入力はすべて整数

入力
入力は以下の形式で標準入力から与えられます．
N
A 1 A 2 ⋯ A N
Q
L 1 R 1
⋮
L Q R Q
 
出力
i=1,2,3,…,Q それぞれについて，アタリの方が多い場合 win を，ハズレの方が多い場合 lose を，
アタリとハズレが同じ場合 draw を，一行ずつ，総計 Q 行に出力してください．
*/

#include <iostream>
using namespace std;

int main(){
  int N,Q;
  cin >> N;
  int hit[N+10],miss[N+10]; //少し余裕を持たせないとダメ
  hit[0]=0;
  miss[0]=0;
  for (int i=1; i<=N; i++){
    int a_i;
    cin >> a_i;
    if (a_i==1){
      hit[i]=hit[i-1]+1;
      miss[i]=miss[i-1];
    }else{
      hit[i]=hit[i-1];
      miss[i]=miss[i-1]+1;
    }
  }
  cin >> Q;
  for (int i=0; i<Q; i++){
    int L,R;
    cin >> L >> R;
    int hits = hit[R]-hit[L-1];
    int misses = miss[R]-miss[L-1];
    if (hits == misses)cout << "draw" << endl;
    else if (hits>misses)cout << "win" << endl;
    else cout << "lose" << endl;
  }
}
