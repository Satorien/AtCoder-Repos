#include <iostream>
#include <algorithm>
using namespace std;
int N,Q,X[100009],A[100009];

int binary(int x){
  int L = 1, R = N, mid;
  while (L<=R){
    mid = (L+R)/2;
    if (x < A[mid]) R = mid-1;
    else if (x == A[mid]) return mid;
    else L = mid+1;
  }
  return R;//見つからなかった場合、ループから脱出するときに大小関係が入れ替わる( A[R] < x < A[L] )
  //よってRはA[R]がxを越えない最大の整数→xより小さい数はR個ある
}

int main(){
  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  sort(A+1,A+N+1);
  cin >> Q;
  for (int i=1; i<=Q; i++) {
    cin >> X[i];
    int prev = binary(X[i]);
    cout << prev << endl;
  }
}
