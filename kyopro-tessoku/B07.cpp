/*
問題文
あるコンビニは時刻 0 に開店し、時刻 T に閉店します。
このコンビニには N 人の従業員が働いており、
i 番目 (1≤i≤N) の従業員は時刻 L i に出勤し、時刻 R i に退勤します。
t=0,1,2,…,T−1 それぞれについて、時刻 t+0.5 にコンビニにいる従業員の数を出力するプログラムを作成してください。

制約
1≤T≤500000
1≤N≤500000
0≤L i <R i ≤T (1≤i≤N)
入力はすべて整数

入力
入力は以下の形式で標準入力から与えられます。
T
N
L 1 R 1
⋮
L N ​R N
 
出力
全体でT 行出力してください。
t+1 行目 (0≤t≤T−1) には、時刻 t+0.5 にコンビニにいる従業員の数を出力してください。
*/

#include <iostream>
using namespace std;

int main(){
  int T,N;
  cin >> T >> N;
  int L[N+1],R[N+1],time[T+1];
  for (int i=0; i<=T; i++)time[i]=0;
  for (int i=1; i<=N; i++){
    cin >> L[i] >> R[i];
    time[L[i]]++;
    time[R[i]]--;
  }
  int ans[T+1];
  ans[0]=time[0];
  cout << ans[0] << endl;
  for (int i=1; i<=T-1; i++){
    ans[i] = ans[i-1]+time[i];
    cout << ans[i] << endl;
  }
}
