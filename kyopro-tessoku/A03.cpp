/*
問題文
赤いカードが N 枚あり、それぞれ整数 P1,P2,⋯,PN  が書かれています。
また、青いカードがN 枚あり、それぞれ整数 Q1,Q2,⋯,QN が書かれています。

太郎君は、赤いカードの中から 1 枚、青いカードの中から 1 枚、
合計 2 枚のカードを選びます。
選んだ 2 枚のカードに書かれた整数の合計が K となるようにする方法は存在しますか。

制約
N は 1 以上 100 以下の整数
K は 1 以上 100 以下の整数
P1,P2,⋯,PN は 1 以上 100 以下の整数
Q1,Q2,⋯,QN は 1 以上 100 以下の整数

入力
入力は以下の形式で標準入力から与えられます。
N K
P1 P2 ⋯ PN
Q1 Q2 ⋯ QN
 
出力
合計を K にする方法が存在するとき Yes、そうでないとき No を出力してください。
*/

#include <iostream>
using namespace std;

int main(){
  int N, K, P[100], Q[100];
  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> P[i];
  for (int i = 1; i <= N; i++) cin >> Q[i];
  
  string ans = "No";
  for (int i = 1; i <= N; i++){
    for (int j = 1; j <= N; j++){
      if (P[i]+Q[j]==K) ans = "Yes";
    }
  }
  cout << ans << endl;
}
