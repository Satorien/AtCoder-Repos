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
