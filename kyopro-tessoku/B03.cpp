#include <iostream>
using namespace std;

int main(){
  int N, A[100];
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];

  string ans = "No";
  for (int i = 1; i <= N-2; i++){
    for (int j = i+1; j <= N-1; j++){
      for (int k = j+1; k <= N; k++){
        if (A[i]+A[j]+A[k]==1000) ans = "Yes";
      }
    }
  }
  cout << ans << endl;
}
