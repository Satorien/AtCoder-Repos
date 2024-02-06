/*
問題文
整数 A と B が与えられます。A+B の値を出力してください。

制約
A は 1 以上 100 以下の整数
B は 1 以上 100 以下の整数
  
入力
入力は以下の形式で標準入力から与えられます。
A B

出力
答えを整数で出力してください。
*/

#include <iostream>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b; //複数の標準入力に対応．スペースや改行があれば区切ってくれるらしい
  cout << a+b << endl;
  return 0;
}
