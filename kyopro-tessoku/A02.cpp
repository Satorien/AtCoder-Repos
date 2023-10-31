#include <bits/stdc++.h> //string型などを扱うときに必要
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
