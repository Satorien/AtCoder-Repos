/*問題文
N 台のプリンターがあり、1 から N までの番号が付けられています。
プリンター i は A i  秒ごとにチラシを 1 枚印刷します。
すなわち、スイッチを入れてから A i  秒後、2A i 秒後、3A i​ 秒後･･･ に印刷します。
すべてのプリンターのスイッチを同時に入れたとき、K 枚目のチラシが印刷されるのは何秒後でしょうか。

制約
1≤N≤100000
1≤K≤10^9
1≤A i​≤10^9
答えは 10^9を超えない
入力はすべて整数

入力
入力は以下の形式で標準入力から与えられます。
N　K
A 1 A 2 ⋯　A N
 
出力
何秒後に K 枚目のチラシが印刷されるかを一行で出力してください。
*/
  
#include <iostream>
using namespace std;

long long N, K, A[100009];

//答えがx以下であればTrue、違えばFalseを返す
bool check(long long x){
  long long sum = 0;
  for (int i=1; i<=N; i++) sum += x/A[i];
  if (sum >= K) return true;
  return false;
}

int main(){
  cin >> N >> K;
  for (int i=1; i<=N; i++) cin >> A[i];
  
  //答えの二分探索を行う
  long long left=1, right=1000000000;
  while (left<right){
    long long mid = (left+right)/2;
    bool answer = check(mid);
    if (answer) right = mid;
    else left = mid+1;
  }
  //left=rightでループを抜けるのでどちらでもOK
  cout << left << endl;
  return 0;
}
