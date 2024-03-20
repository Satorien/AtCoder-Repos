#問題文
#  3 個の数列 A=(A 1 ​ ,…,A N ​ ),B=(B 1 ​ ,…,B M ​ ),C=(C 1 ​ ,…,C L ​ ) が与えられます。
#  さらに数列 X=(X 1 ​ ,…,X Q ​ ) が与えられるので、各 i=1,…,Q に対して次の問題を解いてください。 
#  問題： A,B,C からそれぞれ 1 個ずつ要素を選び、和を X i ​ にすることができるか？ 
#制約 
#  1≤N,M,L≤100 0≤A i ​ ,B i ​ ,C i ​ ≤10 8 1≤Q≤2×10 5 0≤X i ​ ≤3×10 8 
#  入力は全て整数である 
#入力 
#  入力は以下の形式で標準入力から与えられる。 
#  N A 1 ​ … A N ​ M B 1 ​ … B M ​ L C 1 ​ … C L ​ Q X 1 ​ … X Q ​ 
#出力 
#  Q 行出力せよ。 i 行目には、 A,B,C からそれぞれ 1 個ずつ要素を選び和を X i ​ にすることができるならば Yes、できないならば No と出力せよ。

N=int(input());
A=list(map(int, input().split()));
M=int(input());
B=list(map(int, input().split()));
L=int(input());
C=list(map(int, input().split()));

sum = set();
for n in range(N):
  for m in range(M):
    for l in range(L):
      sum_temp = A[n]+B[m]+C[l];
      sum.add(sum_temp);

Q=int(input());
X=list(map(int, input().split()));
for q in range(Q):
  if X[q] in sum:
    print("Yes");
  else:
    print("No");

