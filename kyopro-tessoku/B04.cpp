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
