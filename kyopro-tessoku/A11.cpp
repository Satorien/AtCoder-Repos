/*
問題文 
小さい順に並べられている、要素数 N の配列 A=[A 1 ​ ,A 2 ​ ,⋯,A N ​ ] があります。
要素 X は配列 A の何番目に存在するかを出力してください。 
なお、この問題は単純な全探索（→1.2節）でも解けますが、ここでは二分探索法を使って実装してください。 

制約 
1≤N≤100000 
1≤A 1 ​ <A 2 ​ <⋯<A N ​ ≤10^9 
整数 X は A 1 ​ ,A 2 ​ ,…,A N ​ のいずれかである 

入力 
入力は以下の形式で標準入力から与えられます。 
N X 
A 1 ​ A 2 ​ ⋯ A N ​ 

出力 
要素 X は配列 A の何番目に存在するかを出力してください。
*/

#include <iostream>
using namespace std;
int N,X,A[100009];//予め大域変数として作成

int binary(int x){
  int L = 1, R = N;
  while (L<=R){//L=Rの状態で続けると大小関係が崩れる
    int mid = (L+R)/2;//商の切り捨てがxと比較してどうなるか
    if (x < A[mid]) R = mid-1;
    else if (x == A[mid]) return mid;
    else L = mid+1;
  }
  return -1;
}

int main(){
  cin >> N >> X;
  for (int i=1; i<=N; i++) cin >> A[i]; //インデックスを取り出しやすいようにiを設定している
  cout << binary(X) << endl;
}
