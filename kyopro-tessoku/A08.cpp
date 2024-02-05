/*
問題文 
H×W のマス目があります．
上から i 行目，左から j 列目にあるマス (i,j) には，整数 X i,j ​ が書かれています． 
これについて，以下の Q 個の質問に答えるプログラムを作成してください． 
i 個目の質問：
左上 (Ai,Bi) 右下 (Ci,Di) の長方形領域に書かれた整数の総和は？ 

制約 
1≤H,W≤1500 
1≤Q≤100000 
0≤X i,j≤9 
1≤Ai≤Ci≤H 
1≤Bi≤Di≤W 
入力はすべて整数 

入力 
入力は以下の形式で標準入力から与えられます．
H W 
X1,1 X1,2​ ⋯ X1,W 
​ ⋮ 
XH,1 XH,2​ ⋯ XH,W ​
Q 
A1 B1​ C1​ D1
​ ⋮ 
AQ BQ​ CQ​ DQ ​ 

出力 
Q 行にわたって出力してください． i 行目には，質問 i の答えを出力してください．
*/

#include <iostream>
using namespace std;

int main(){
  int H,W,Q;
  cin >> H >> W;
  int X[1502][1502],sum[1502][1502];
  for (int i=1; i<=H; i++){
    X[i][0]=0;
    X[i][W+1]=0;
    for (int j=1; j<=W; j++)cin >> X[i][j];
  }
  for (int j=0; j<=W+1; j++){
    X[0][j]=0;
    X[H+1][j]=0;
  }
  //二次元累積和の計算
  for (int i=1; i<=H; i++){
    for (int j=1; j<=W; j++){
      sum[i][j]=sum[i][j-1]+X[i][j]; //まずは行内で累積和を取る
    }
    for (int j=1; j<=W; j++)sum[i][j]+=sum[i-1][j]; //それが終わってから前の列の和を足す
  }
  cin >> Q;
  for (int i=1; i<=Q; i++){
    int a,b,c,d,ans;
    cin >> a >> b >> c >> d;
    ans = sum[c][d]+sum[a-1][b-1]-sum[a-1][d]-sum[c][b-1]; //必要のない部分を除いてから引きすぎた部分を足す
    cout << ans << endl;
  }
}
