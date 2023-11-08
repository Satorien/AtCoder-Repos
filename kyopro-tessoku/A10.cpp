#include <iostream>
using namespace std;

int main(){
  int N,D;
  cin >> N;
  int A[N+1];
  for (int i=1; i<=N; i++) cin >> A[i];
  cin >> D;
  int L[D+1], R[D+1];
  for (int i=1; i<=D; i++) cin >> L[i] >> R[i];

  //to[i]でi号室までの最大値、from[i]でi号室以降の最大値を計算しておく
  int to[N+2],from[N+2];
  to[0] = 0;
  from[N+1] = 0;
  for (int i=1; i<=N; i++){
    if (to[i-1]<A[i])to[i]=A[i];
    else to[i]=to[i-1];
    
    if (from[N-i+2]<A[N-i+1])from[N-i+1]=A[N-i+1];
    else from[N-i+1]=from[N-i+2];
  }

  //出力
  for (int i=1; i<=D; i++){
    if(to[L[i]-1]>from[R[i]+1]) cout << to[L[i]-1] << endl;
    else cout << from[R[i]+1] << endl;
  }
}
