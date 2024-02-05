/*
問題文 
整数 N が 10 進法表記で与えられます。 
N を 2 進法に変換した値を出力するプログラムを作成してください。 

制約 
N は 1 以上 1000 以下の整数 

入力 
入力は以下の形式で標準入力から与えられます。 
N 

出力
N を 2 進法に変換した値を、 10 桁で出力してください。 
桁数が足りない場合は、左側を 0 で埋めてください。
*/

#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  for (int i = 9; i >= 0; i--){
    int x = (1<<i); //ビット演算子<<を使うとビットの位を動かせる．ここでは1を左にi桁動かせるので2のi乗していることになる
    cout << (N/x)%2; //i桁目の代入
  }
  cout << endl;
}
