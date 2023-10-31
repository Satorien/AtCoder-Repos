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
