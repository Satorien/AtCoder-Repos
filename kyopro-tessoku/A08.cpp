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
