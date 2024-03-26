/*
問題文
  N 枚のカードがあり、i 枚目 (1≤i≤N) のカードには整数Aiが書かれています。
  カードの選び方は全部で2^N 通りありますが、選んだカードの合計がちょうど 
  K となるようにする方法は存在しますか。

制約
  1≤N≤30
  1≤K≤10^8
  1≤Ai≤10^8 
  入力はすべて整数

入力
  入力は以下の形式で標準入力から与えられます。
  N　K
  A1 A2​ ⋯ AN
​
出力
  合計が K となる可能性がある場合 Yes、そうでない場合 No を出力してください。
*/

//かなり考えても分からなかったので写経した
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 配列にあるカードからいくつか選んだ時の合計を列挙する
// ビット全探索で実装する
vector<long long> Enumerate(vector<long long> A){
  vector<long long> SumList;
  for (int i=0; i<(1 << A.size()); i++){ // 2^N個の可能性を列挙する
    long long sum=0;
    for (int j=0; j < A.size(); j++){
      int wari = (1<<j);
      if ((i/wari)%2 == 1) sum+=A[j]; //iのjビット目が１ならj番目のカードを使う
    }
    SumList.push_back(sum); //リストの後ろに入れる
  }
  return SumList;
}

long long N, K, A[39];

int main(){
  //標準入力
  cin >> N >> K;
  for (int j=1; j<=N; j++){
    cin >> A[j];
  }
  
  //カードを半分に分ける
  vector<long long> L1, L2;
  for (int i=1; i<=N/2; i++) L1.push_back(A[i]);
  for (int i=N/2+1; i<=N; i++) L2.push_back(A[i]);
  
  //あり得るカードの合計を列挙する
  vector<long long> Sum1 = Enumerate(L1);
  vector<long long> Sum2 = Enumerate(L2);
  sort(Sum1.begin(), Sum1.end());
  sort(Sum2.begin(), Sum2.end());
  
  //二分探索を実行
  for (int i=0; i<Sum1.size(); i++){
    int pos = lower_bound(Sum2.begin(), Sum2.end(), K-Sum1[i])-Sum2.begin();
    if (pos < Sum2.size() && Sum2[pos] == K-Sum1[i]){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
