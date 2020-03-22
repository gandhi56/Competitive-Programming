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
int a[100][50];
int A;

int dp[200][200];

int solve(int x, int i){
  if (dp[x][i] != -1)   return dp[x][i];
  if (x == 0)   return dp[x][i] = 0;
  if (i == p-1){
    int val = 0;
    for (int k = 0; k < x; ++k)
      val += a[i][k];
    return dp[x][i] = val;
  }

  int ans = 0;
  int val = 0;
  for (int y = 0;  y <= x; ++y){
    val =0;
    for (int k = 0; k < y; ++k)
      val += a[i][k];
    ans = max(ans, val + solve(x - y, i+1));
  }
  return dp[x][i] = ans;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  for (int tt =1; tt <= t; ++tt){
    cin >> n >> k >> p;

    memset(a, 0, sizeof(a));
    //memset(dp, -1, sizeof(dp));
    
    for (int i = 0; i < 200; ++i)
      for (int j = 0; j < 200; ++j)
        dp[i][j] = -1;
    
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < k; ++j)
        cin >> a[i][j];

    A = solve(p, 0);
    
    cout << "Case #" << tt << ": " << A << endl;
  }
  
  return 0;
}
