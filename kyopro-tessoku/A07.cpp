#include <iostream>
using namespace std;

int main(){
  int D,N;
  cin >> D >> N;
  int L[N+1],R[N+1],day[D+1];
  for (int i=1; i<=N; i++){
    cin >> L[i] >> R[i];
  }
  for (int i=1; i<=D; i++)day[i]=0; //初期状態で0になっていないこともあるので初期化
  for (int i=1; i<=N; i++){
    for (int j=L[i]; j<=R[i]; j++) day[j]=day[j]+1; //ここは前日比の配列を作ることで簡単に計算できる
  } //具体的にはL[i]日目で＋1、R[i]＋1日目で―1を記憶しておく
  for (int i=1; i<=D; i++) cout << day[i] << endl;
}
