#define MAXN 200
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int dp[MAXN][MAXN][MAXN];

int solve(int a, int b, int c){
  if (a < 0 or b < 0 or c < 0)  return 0;
  if (dp[a][b][c] != -1)  return dp[a][b][c];
  if (a >= 1 and b >= 2)  dp[a][b][c] = 3 + solve(a-1, b-2, c);
  if (b >= 1 and c >= 2)  dp[a][b][c] = max(dp[a][b][c], 3 + solve(a, b-1, c-2));
  return dp[a][b][c];
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--){
    for (int i =0 ; i < MAXN; ++i){
      for (int j = 0; j < MAXN; ++j){
        for (int k = 0; k < MAXN; ++k){
          dp[i][j][k] = -1;
        }
      }
    }
    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c)+1 << endl;
  }
  return 0;
}
