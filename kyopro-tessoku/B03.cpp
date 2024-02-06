/*
問題文
N 個の商品があり、商品 i (i=1,2,⋯,N) の価格は A i 円です。
異なる 3 つの商品を選び、合計価格をピッタリ 1000 円にする方法は存在しますか。

制約
3≤N≤100
1≤A i ≤1000
入力はすべて整数

入力
入力は以下の形式で標準入力から与えられます。
N
A 1 A 2 ⋯ A N
 
出力
合計を 1000 円にする方法が存在する場合 Yes、そうでない場合 No と出力してください。
*/
  
#include <iostream>
using namespace std;

int main(){
  int N, A[100];
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];

  string ans = "No";
  for (int i = 1; i <= N-2; i++){
    for (int j = i+1; j <= N-1; j++){
      for (int k = j+1; k <= N; k++){
        if (A[i]+A[j]+A[k]==1000) ans = "Yes";
      }
    }
  }
  cout << ans << endl;
}
