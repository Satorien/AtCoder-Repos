/*
問題文 
ALGO 王国は H×W のマス目で表されます．
最初は，どのマスにも雪が積もっていませんが，これから N 日間にわたって雪が降り続けます．
上から i 行目，左から j 列目のマスを (i,j) とするとき， t 日目には 
「マス (A t ​ ,B t ​ ) を左上とし，マス (C t ​ ,D t ​ ) を右下とする長方形領域」
の積雪が 1cm だけ増加することが予想されています． 
最終的な各マスの積雪を出力するプログラムを作成してください． 

制約 
1≤H,W≤1500 
1≤N≤100000 
1≤Ai≤Ci≤H
1≤Bi≤Di≤W 
入力はすべて整数 

入力 
入力は以下の形式で標準入力から与えられます． 
H W N 
A 1 ​ B 1 ​ C 1 ​ D 1 ​ 
A 2 ​ B 2 ​ C 2 ​ D 2 ​
⋮ 
A N ​ B N ​ C N ​ D N ​ 

出力 
マス (i,j) の最終的な積雪を Z i,j ​ とするとき，以下の形式で出力してください． 
Z 1,1 ​ Z 1,2 ​ ⋯ Z 1,W ​
⋮ 
Z H,1 ​ Z H,2 ​ ⋯ Z H,W ​
*/

#include <iostream>
using namespace std;

int main(){
  int H,W,N;
  cin >> H >> W >> N;

  int point[H+2][W+2],sum[H+2][W+2];
  for (int i=0; i<=H+1; i++){
    for (int j=0; j<=W+1; j++)point[i][j]=0;
  }
  //二次元累積和で処理するために足す数を準備する
  for (int i=1; i<=N; i++){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    point[a][b]+=1;
    point[c+1][b]-=1;
    point[a][d+1]-=1;
    point[c+1][d+1]+=1;
  }
  //二次元累積和を取って積雪量を計算と同時に出力
  for (int i=1; i<=H; i++){
    sum[i][0]=point[i][0];
    for (int j=1; j<=W; j++){
      sum[i][j]=sum[i][j-1]+point[i][j];
      sum[0][j]=point[0][j];
    }
    for (int j=1; j<=W; j++){
      sum[i][j]+=sum[i-1][j];
      cout << sum[i][j] << " ";
    }
    cout << endl;
  }
}
