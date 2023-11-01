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
