/*
問題文
2 進法表記で表された整数 N が与えられます。
N を 10 進法に変換した値を出力するプログラムを作成してください。

制約
N の長さは 1 文字以上 8 文字以下
N は 0 と 1 からなる
N の先頭の桁は 1 である

入力
入力は以下の形式で標準入力から与えられます。
N

出力
答えを整数で出力してください。
*/ 

#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int N, ans;
  ans = 0;
  cin >> N;
  for (int i = 7; i>=0; i--){
    int x =  int(N/std::pow(10,i)); //cmathライブラリ必要
    ans += (x%10 << i);
  }
  cout << ans << endl;
}
