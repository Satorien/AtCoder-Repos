/*
問題文 
ある会社では D 日間にわたってイベントが開催され， N 人が出席します．
参加者 i は L i ​ 日目から R i ​ 日目まで出席する予定です． 
各日の出席者数を出力するプログラムを作成してください． 

制約 
1≤D,N≤10^5 
1≤Li≤Ri≤D 
入力はすべて整数 

入力 
入力は以下の形式で標準入力から与えられます． 
D 
N 
L 1 ​ R 1 
​ ⋮ 
L N ​ R N ​ 

出力 
D 行にわたって出力してください． d 行目には， d 日目の出席者数を出力してください．
*/

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
    for (int j=L[i]; j<=R[i]; j++) day[j]=day[j]+1; //ここは前日比の配列を作る方が簡単に計算できた
  } //具体的にはL[i]日目で＋1、R[i]＋1日目で―1を記憶しておく
  for (int i=1; i<=D; i++) cout << day[i] << endl;
}
