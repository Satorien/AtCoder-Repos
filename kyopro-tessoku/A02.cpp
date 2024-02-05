/*
問題文
N 個の整数 A1,A2,⋯,AN​の中に、整数 X が含まれるかどうかを
判定するプログラムを作成してください。

制約
N は 1 以上 100 以下の整数
X は 1 以上 100 以下の整数
A1,A2,⋯,AN は 1 以上 100 以下の整数

入力
入力は以下の形式で標準入力から与えられます。
N X
A1 A2 ⋯ AN
​
出力
整数 X が含まれるとき Yes、含まれないとき No と出力してください。
*/
#include <bits/stdc++.h> //string型などを扱うときに必要（追記：関係なさそう）
using namespace std;

int main(){
  int n,x,A[100];
  string ans = "No"; //ダブルクォーテーションとシングルクォーテーションを区別している．stringの定義にはダブル
  cin >> n >> x;
  for (int i = 1; i<=n; i++)cin >> A[i]; //多数入力に関してはfor文などで受け取る
  for (int i = 1; i<=n; i++){
    if (A[i]==x) ans = "Yes";
  }
  cout << ans << endl;
}
