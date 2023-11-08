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
