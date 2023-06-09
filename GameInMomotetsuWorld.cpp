#include<bits/stdc++.h>
using namespace std;
//https://atcoder.jp/contests/abc201/tasks/abc201_d

#define    ff        first
#define    ss        second
#define    ll        long long
#define    w(t)      ll t; cin >> t; while(t--)
#define    out       cout << "Case #";
/*------------------------------------------------------------------------------------------------------
   kon bola mei gaata nahi 
   mere lund pe bajj
*/


vector <vector <ll>> DP;
vector <vector <char>> G;
//1 -> it's my chance
ll N, M;

bool isValid(int x, int y) {
  return x >= 0 && y >= 0 && x < N && y < M;
}
ll F(ll i, ll j) {
  if(i == N - 1 && j == M - 1) {
    if(G[i][j] == '-')return -1;
    else return 1;
  }
  if(DP[i][j] != -1e8)return DP[i][j];
  ll A = INT_MIN;
  if(isValid(i + 1, j)){
    A = max(A, F(i + 1, j));
  }
  if(isValid(i, j + 1)){
    A = max(A, F(i, j + 1));
  }
  return DP[i][j] = -A + ((G[i][j] == '-'? -1 : 1));
}

void solve() {
  cin >> N >> M;

  G.resize(N, vector <char> (M));
  for (ll i = 0; i < N; ++ i){
    for (ll j = 0; j < M; ++j) {
      cin >> G[i][j];
    }
  }

  if(N == 1 && M == 1){
    cout << "Draw" << endl;
    return;
  }

  DP.resize(N, vector <ll> (M, -1e8));

  if((isValid(0, 1) && F(0, 1) > 0) || (isValid(1, 0) && F(1, 0) > 0)) {
    cout << "Takahashi" << endl;
  }
  else if((isValid(0, 1) && F(0, 1) == 0) || (isValid(1, 0) && F(1, 0) == 0)) {
    cout << "Draw" << endl;
  }
  else cout << "Aoki" << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  // w(t){
  //   solve();
  // }
  solve();
  return 0;
}
