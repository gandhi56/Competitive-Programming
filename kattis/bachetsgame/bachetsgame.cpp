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

int n, m;
vi stones;
vi dp;
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  dp.resize(1000001);
  while (cin >> n >> m){
    stones.resize(m);
    for (auto& x : stones)    cin >> x;  
    dp[0] = false;
    for (int i = 1; i <= n; ++i){
      dp[i] = false;
      for (int j = 0; j < m; ++j){
        if (i >= stones[j] and !dp[i - stones[j]]){
          dp[i] = true;
          break;
        }
      }
    }
    cout << (dp[n]? "Stan" : "Ollie") << " wins" << endl;
  }

  
  return 0;
}
