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
