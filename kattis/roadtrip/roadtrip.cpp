#define INF 0x3f3f3f3f
#define pb(x) push_back(x)
#define sz(x) (int)(x).size()
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vii;
typedef vector<vector<ii>> viii;
#define MAXN 200010
#define MAXG 20000

int n, g;
vector<int> d, c;
int dp[MAXN];
int solve(int i, int j){
  if (i == n-1) return 0;
  if (j == 0)   return INF;
  int ans = INF;
  for (int k = i+1; k < n; ++k){
    int dist = (i == -1? d[k] : d[k] - d[i]);
    if (dist <= j){
      for (int m = 0; m <= g-j; ++m){
        int cost = m*c[k] + dist + solve(k, j - dist + m);
        ans = min(ans, cost);
      }
    }
  }
  return dp[i] = ans;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  cin >> n >> g;
  d.resize(n);
  c.resize(n);

  for (int i = 0; i < n+1; ++i)
    dp[i] = INF;

  for (int i = 0; i < n; ++i)
    cin >> d[i] >> c[i];

  cout << solve(-1, g) << endl;

  return 0;
}
