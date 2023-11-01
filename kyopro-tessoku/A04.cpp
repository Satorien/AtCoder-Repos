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
