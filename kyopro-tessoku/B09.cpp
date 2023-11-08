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
