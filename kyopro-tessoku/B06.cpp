#include <iostream>
using namespace std;

int main(){
  int N,Q;
  cin >> N;
  int hit[N+10],miss[N+10]; //少し余裕を持たせないとダメ
  hit[0]=0;
  miss[0]=0;
  for (int i=1; i<=N; i++){
    int a_i;
    cin >> a_i;
    if (a_i==1){
      hit[i]=hit[i-1]+1;
      miss[i]=miss[i-1];
    }else{
      hit[i]=hit[i-1];
      miss[i]=miss[i-1]+1;
    }
  }
  cin >> Q;
  for (int i=0; i<Q; i++){
    int L,R;
    cin >> L >> R;
    int hits = hit[R]-hit[L-1];
    int misses = miss[R]-miss[L-1];
    if (hits == misses)cout << "draw" << endl;
    else if (hits>misses)cout << "win" << endl;
    else cout << "lose" << endl;
  }
}
