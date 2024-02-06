/*
問題文
二次元平面上に N 個の点があります．
i 個目の点の座標は (X i ,Y i) です． 
「x 座標が a 以上 c 以下であり，y 座標がb 以上 d 以下であるような点は何個あるか？」 という形式の質問が 
Q 個与えられるので，それぞれの質問に答えるプログラムを実装してください． なお，入力される値はすべて整数です．

制約
1≤N,Q≤100000
1≤X i ,Y i ≤1500
1≤a i​ ≤c i​ ≤1500
1≤b i ≤d i ≤1500
入力はすべて整数

入力
入力は以下の形式で標準入力から与えられます．
N
X 1 Y 1
⋮
X N Y N
Q
a 1 b 1 c 1 d 1
​⋮
a Q b Q c Q d Q
​
出力
Q 行にわたって出力してください．
i 行目には，i 個目の質問の答えを出力してください．
*/

#include <iostream>
using namespace std;

int main(){
  int N,Q,maxX,maxY;
  cin >> N;
  maxX=0;
  maxY=0;
  int point[1502][1502],sum[1502][1502];
  for (int i=0; i<=1501; i++){
    for (int j=0; j<=1501; j++)point[i][j]=0;
  }
  for (int i=1; i<=N; i++){
    int x,y;
    cin >> x >> y;
    point[x][y]++;
    if (x>maxX)maxX=x;
    if (y>maxY)maxY=y;
  }
  for (int i=1; i<=maxX; i++){
    for (int j=1; j<=maxY; j++){
      sum[i][j]=sum[i][j-1]+point[i][j];
    }
    for (int j=1; j<=maxY; j++)sum[i][j]+=sum[i-1][j];
  }
  cin >> Q;
  for (int i=1; i<=Q; i++){
    int a,b,c,d,ans;
    cin >> a >> b >> c >> d;
    ans = sum[c][d]+sum[a-1][b-1]-sum[a-1][d]-sum[c][b-1];
    cout << ans << endl;
  }
}
