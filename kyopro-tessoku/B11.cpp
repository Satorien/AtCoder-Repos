/*
問題文
小さい順に並んでいるとは限らない、要素数 N の配列 A=[A 1,A 2​,⋯,A N] が与えられます。
それについて、以下の Q 個の質問に答えるプログラムを作成してください。
i (1≤i≤Q) 個目の質問：配列 A には X i​ より小さい要素が何個あるか？

制約
1≤N,Q≤100000
1≤A i≤10^9 (1≤i≤N)
1≤X i≤10^9 (1≤i≤Q)
入力はすべて整数

入力
入力は以下の形式で標準入力から与えられます。
N
A 1 A 2 ⋯ A N 
Q
X 1
X 2 
⋮
X Q

出力
それぞれの質問に対する答えを、順番に Q 行出力してください。
*/

#include <iostream>
#include <algorithm>
using namespace std;
int N,Q,X[100009],A[100009];

int binary(int x){
  int L = 1, R = N, mid;
  while (L<=R){
    mid = (L+R)/2;
    if (x < A[mid]) R = mid-1;
    else if (x == A[mid]) return mid;
    else L = mid+1;
  }
  return R;//見つからなかった場合、ループから脱出するときに大小関係が入れ替わる( A[R] < x < A[L] )
  //よってRはA[R]がxを越えない最大の整数→xより小さい数はR個ある
}

int main(){
  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  sort(A+1,A+N+1);
  cin >> Q;
  for (int i=1; i<=Q; i++) {
    cin >> X[i];
    int prev = binary(X[i]);
    cout << prev << endl;
  }
}
