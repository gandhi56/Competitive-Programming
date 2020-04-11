#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct pos{
  pii p;
  int sum;
  pos(int r, int k, int s)  :   p({r,k}), sum(s){}
};

int dp[1000][1000];

void construct(){
  dp[1][1] = 1;
  for (int r = 1; r < 1000; ++r){
    for (int k = 1; k <= r; ++k){
      if (k == 1 or r == k){
        dp[r][k] = 1;
      }
      else{
        dp[r][k] = dp[r-1][k-1] + dp[r-1][k];
      }
    }
  }
}

int f(int r, int k){
  return (r*(r-1))/2 + k;
}

int getsum(int i, int j){
  if (i < 1000 and j < 1000)    return dp[i][j];
  if (j == 1 or j == i) return 1;
  return getsum(i-1, j-1) + getsum(i-1,j);
}

bool ok(int r, int k){
  return r >= 1 and k >= 1 and k <= r;
}

void solve(int tc){
  int n;
  cin >> n;
/*
  //bitset<100000> seen;
  vector<bool> seen(100000000, false);
  pii par[700][700];
  for (int i= 0; i < 700; ++i){
    for (int j = 0; j < 700; ++j){
      par[i][j] = {-1,-1};
    }
  }

  queue<pos> q;
  q.push(pos(1,1,1));
  pos curr(0,0,0);
  while (!q.empty()){
    curr = q.front(); q.pop();
    if (curr.sum == n)  break;
    if (curr.sum > n)   continue;
    int r = curr.p.first;
    int k = curr.p.second;

    for (int rr : {-1, -1, 0, 0, 1, 1}){
      for (int kk : {-1, 0, -1, 1, 0, 1}){
        if (!ok(r+rr, k+kk))    continue;
        if (seen[f(r+rr, k+kk)])    continue;
        par[r+rr][k+kk] = {r, k};
        seen[f(r+rr, k+kk)] = true;
        q.push(pos(r+rr, k+kk, curr.sum + getsum(r+rr, k+kk)));
      }
    }
  }

  vector<pii> walk;
  pii p = curr.p;
  while (1){
    walk.push_back(p);
    if (p.first == 1 and p.second == 1) break;
    p = par[p.first][p.second];
  }
  reverse(all(walk));
  cout << "Case #" << tc << ": " << endl;
  for (auto w : walk)
    cout << w.first << ' ' << w.second << endl;
  //cout << sz(walk) << endl;

*/

  cout << "Case #" << tc << ": " << endl;
  if (n == 501){
    cout << "1 1" << endl;
    cout << "1 2" << endl;
    cout << "2 1" << endl;
    for (int r = 3; r <= 500; ++r){
      cout << r << ' ' << 1 << endl;
    }
  }
  else{
    for (int r = 1; r <= n; ++r){
      cout << r << ' ' << 1 << endl;
    }

  }

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  construct();

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; ++tc)
    solve(tc);

  return 0;
}
