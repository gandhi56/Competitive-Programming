#define LIN cout << __LINE__ << endl;
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

int n, k, p;
int a[200][200];
int dp[200][2000];

int f(int p, int pl){
  if (dp[p][pl] != -1)   return dp[p][pl];
  if (p == n)   return 0;
  int b = 0;
  int cur = 0;
  for (int i = 0; i <= k; ++i){
    if (pl - i >= 0)
      b = max(b, cur + f(p+1, pl - i));
    if (i != k)
      cur += a[p][i];
  }
  return dp[p][pl] = b;
}

int solve(){
  cin >> n >> k >> p;
  memset(dp, -1, sizeof(dp));
  for (int i =0; i < n; ++i){
    for (int j = 0; j < k; ++j)
      cin >> a[i][j];
  }

  return f(0, p);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; ++tc){
    cout << "Case #" << tc << ": " << solve() << endl;
  }
  
  return 0;
}
