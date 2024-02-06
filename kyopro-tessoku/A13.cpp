/*
問題文
N 個の整数が黒板に書かれています。書かれた整数は小さい順に A 1,A 2,⋯,A Nです。
異なる 2 つの整数のペアを選ぶ方法は全部で N(N−1)/2 通りありますが、
その中で差が K 以下であるような選び方は何通りありますか。

制約
1≤N≤100000
1≤K≤10^9
1≤A 1<A 2<⋯<A N≤10^9
入力はすべて整数

入力
入力は以下の形式で標準入力から与えられます。
N K
A 1​ A 2 ⋯ A N
 
出力
差が K 以下である整数のペアの選び方を一行に出力してください。
*/

#include <iostream>
using namespace std;

int N, K, A[100009], R[100009];

int main(){
  cin >> N >> K;
  for (int i=1;i<=N;i++) cin >> A[i];
  long long sum = 0;
  //しゃくとり法
  for (int j=1; j<=N-1; j++){//A[j]のペアを探しているのでN-1までで十分
    if (j==1) R[j]=1;
    else R[j]=R[j-1];//スタート地点を確実にOKな場所にすれば計算量を減らせる
    //次に行ってもOKなら次に行く　Nまで行かないように気を付ける
    while (A[R[j]+1]-A[j]<=K && R[j]<N) R[j]++;
    sum+=R[j]-j;//既にカウントしてるものを除く
  }
  cout << sum << endl;
  return 0;
}