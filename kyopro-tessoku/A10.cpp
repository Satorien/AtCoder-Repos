/*
問題文 
あるリゾートホテルには， 1 号室から N 号室までの N 個の部屋があります． 
i 号室は A i ​ 人部屋です．
このホテルでは D 日間にわたって工事が行われることになっており， 
d 日目は L d ​ 号室から R d ​ 号室までの範囲を使うことができません． 
d=1,2,⋯D について， d 日目に使える中で最も大きい部屋は何人部屋であるか，
出力するプログラムを作成してください． 

制約 
3≤N≤100000 
1≤D≤100000 
1≤Ai≤100 
2≤Li≤Ri≤N−1 
入力はすべて整数 

入力 
入力は以下の形式で標準入力から与えられます． 
N 
A 1 ​ A 2 ​ ⋯ A N ​ 
D 
L 1 ​ R 1 ​ 
⋮ 
L D ​ R D ​ 

出力 
D 行にわたって出力してください． 
d 行目には， d 日目に使える中で最も大きい部屋は何人部屋であるかを出力してください．
*/

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
