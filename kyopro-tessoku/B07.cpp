#include <iostream>
using namespace std;

int main(){
  int T,N;
  cin >> T >> N;
  int L[N+1],R[N+1],time[T+1];
  for (int i=0; i<=T; i++)time[i]=0;
  for (int i=1; i<=N; i++){
    cin >> L[i] >> R[i];
    time[L[i]]++;
    time[R[i]]--;
  }
  int ans[T+1];
  ans[0]=time[0];
  cout << ans[0] << endl;
  for (int i=1; i<=T-1; i++){
    ans[i] = ans[i-1]+time[i];
    cout << ans[i] << endl;
  }
}
