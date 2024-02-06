/*
問題文
正の整数 N が与えられます。x^3+x=N を満たす正の実数 x を出力してください。
ただし、相対誤差または絶対誤差が 0.001 以下であれば正解とします。

制約
1≤N≤100000
N は整数

入力
入力は以下の形式で標準入力から与えられます。
N

出力
答えを出力してください。絶対誤差または相対誤差が 0.001 未満であれば許容されます。
*/

#include <iostream>
#include <cmath>
using namespace std;

long long N;

//そのままdoubleでやると上手く出来なかったので1000xを整数値として求めてから1000で割って答えとした
//満たすべき式は(1000x)^3+10^6(1000x)=10^9N

//解説によると普通にdoubleでも実装可能
//1.0*Nと比較して、left=midかright=midで更新、仮に20回繰り返すと幅は十分小さくなる
//最後の出力ではprintf("%.3lf\n")などとすれば小数点以下3桁のdouble型で出力できる

bool check(long long x){
  long long func= std::pow(x,3)+1000000*x;
  if (func>=N) return true;
  return false;
}

int main(){
  cin >> N;
  N*=1000000000;
  long long left=1, right=100000;
  while (left<right){
    long long mid = (left+right)/2;
    if (check(mid)) right = mid;
    else left = mid+1;
  }
  
  cout << left/1000.0<< endl;
  return 0;
}
