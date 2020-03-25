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

int solve(vi& p, vi& c, int n){

  vb used(n, false);
  int ans = INF;
  for (int st = 0; st < n; ++st){
    if (used[st])   continue;
    
    vi cycle;
    int v = st;
    while (!used[v]){
      used[v] = true;
      cycle.push_back(v);
      v = p[v];
    }

    for (int step = 1; step < sz(cycle)+1; ++step){
      if (sz(cycle) % step != 0)    continue;

      for (int s = 0; s < step; ++s){
        bool eq = true;
        for (int pos = s; pos + step < sz(cycle) and eq; pos += step){
          if (c[cycle[pos]] != c[cycle[pos  + step]])
            eq = false;
        }

        if (eq){
          ans = min(ans, step);
          break;
        }
      }
    }
  }

  return ans;

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;

    vi p(n);
    for (int i = 0; i < n; ++i){
      cin >> p[i];
      --p[i];
    }

    vi c(n);
    for (int i = 0; i < n; ++i)    cin >> c[i];

    cout << solve(p, c, n) << endl;

  }
  
  return 0;
}
