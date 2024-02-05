/*
問題文
赤・青・白の 3 枚のカードがあります。
太郎君は、それぞれのカードに1 以上 N 以下の整数を書かなければなりません。
3 枚のカードの合計を K にするような書き方は何通りありますか。

制約
N は 1 以上 3000 以下の整数
K は 3 以上 9000 以下の整数

入力
入力は以下の形式で標準入力から与えられます。
N K

出力
答えを整数で出力してください。
*/

#include <iostream>
using namespace std;

int main(){
  int N,K,count;
  count = 0;
  cin >> N >> K;
  for (int i=1; i<=N; i++){
    for (int j=i; j<=N; j++){
      if (j<=K-i-j && K-i-j<=N){ //1<=x<=5のような表記は出来ない
        if (i == j || j == K-i-j){
          if (i == K-i-j) count += 1;
          else count += 3;
        }
        else count += 6;
      }
    }
  }
  cout << count << endl;
}
