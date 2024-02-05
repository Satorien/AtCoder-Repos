/*
問題文 
遊園地「ALGO-RESORT」では N 日間にわたるイベントが開催され、 
i 日目 (1≤i≤N) には A i ​ 人が来場しました。 
以下の合計 Q 個の質問に答えるプログラムを作成してください。 
1 個目の質問： L 1 ​ 日目から R 1 ​ 日目までの合計来場者数は？ 
2 個目の質問： L 2 ​ 日目から R 2 ​ 日目までの合計来場者数は？ 
: 
Q 個目の質問： L Q ​ 日目から R Q ​ 日目までの合計来場者数は？ 

制約 
1≤N,Q≤10^5
1≤Ai≤10000 
1≤Li≤Ri≤N 
入力はすべて整数 

入力 
入力は以下の形式で標準入力から与えられます。 
N Q 
A 1 ​ A 2 ​ ⋯ A N ​ 
L 1 ​ R 1 ​
L 2 ​ R 2 ​ 
: 
L Q ​ R Q ​ 

出力 
全体で Q 行出力してください。 
i行目 (1≤i≤Q) には、 i 個目の質問への答えを整数で出力してください。
*/

#include <iostream>
using namespace std;

int main(){
  int N,Q;
  cin >> N >> Q;
  int A[N];
  A[0]=0;
  for (int i=1; i<=N; i++){
    int a_i;
    cin >> a_i;
    if(i==1)A[i]=a_i;
    else A[i]=A[i-1]+a_i; //累積和のリストを作っておくことで計算が楽になる
  }
  for (int i=0; i<Q; i++){
    int L,R;
    cin >> L >> R;
    cout << A[R]-A[L-1] << endl;
  }
}
