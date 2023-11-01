#include <iostream>
using namespace std;

int main(){
  int N,Q;
  cin >> N >> Q;
  int A[N], LR[Q];
  A[0]=0;
  for (int i=1; i<=N; i++){
    int a_i;
    cin >> a_i;
    if(i==1)A[i]=a_i;
    else A[i]=A[i-1]+a_i; //累積和のリストを作っておくことで計算が楽になる
  }
  for (int i=0; i<Q; i++){
    int L,R;
    cin >> L >> R;
    cout << A[R]-A[L-1] << endl;
  }
}
