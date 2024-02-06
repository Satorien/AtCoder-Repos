/*
問題文
二次元平面上に N 枚の紙があります．
それぞれの紙は，各辺が x 軸または y 軸に平行であるような長方形となっています． 
また，i 枚目の紙の左下座標は (A i,B i) であり，右上座標は (C i ,D i) です．
1 枚以上の紙が置かれている部分の面積を求めてください． なお，入力される値はすべて整数です．

制約
1≤N≤100000
0≤A i <C i ≤1500
0≤B i <D i ≤1500
入力はすべて整数

入力
入力は以下の形式で標準入力から与えられます．
N
A 1 B 1 C 1​ D 1 
⋮
A N B N C N D N
​
出力
答えを 1 行に出力してください．
*/
#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  int area = 0;
  int point[1502][1502],sum[1502][1502];//sumは(i-0.5,j-0.5)にある紙の枚数、pointはそれを求めるための前準備
  int maxX=0;
  int maxY=0;
  
  for (int i=0; i<=1501; i++){
    for (int j=0; j<=1501; j++)point[i][j]=0;
  }
  for (int i=1; i<=N; i++){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    point[a+1][b+1]+=1;
    point[c+1][b+1]-=1;
    point[a+1][d+1]-=1;
    point[c+1][d+1]+=1;
    if (maxX<c)maxX=c;
    if (maxY<d)maxY=d;
  }
  for (int i=1; i<=maxX; i++){
    sum[i][0]=point[i][0];
    for (int j=1; j<=maxY; j++){
      sum[i][j]=sum[i][j-1]+point[i][j];
      sum[0][j]=point[0][j];
    }
    for (int j=1; j<=maxY; j++){
      sum[i][j]+=sum[i-1][j];
      if(sum[i][j]>0)area+=1;
    }
  }
  cout << area << endl;
}
