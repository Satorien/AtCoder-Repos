/*
問題文
A 以上 B 以下の整数のうち、100 の約数であるものは存在しますか。

制約
1≤A≤B≤100
入力はすべて整数

入力
入力は以下の形式で標準入力から与えられます。
A B

出力
100 の約数が存在する場合 Yes、そうでない場合 No を出力してください。
*/

#include <iostream>
using namespace std;

int main(){
  int A,B;
  string ans = "No";
  cin >> A >> B;
  for (int i=A; i<=B; i++){
    if (100%i == 0) ans = "Yes";
  }
  cout << ans << endl;
}
