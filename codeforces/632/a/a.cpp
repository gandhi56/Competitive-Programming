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

int n, m;
string g[200];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while (t--){
    cin >> n >> m;

    for (int i =0 ; i < n; ++i){
      g[i].clear();
      g[i].push_back((i&1)?'B':'W');
      for (int j = 0; j < m-1; ++j){
        g[i].push_back((g[i].back() == 'W'?'B':'W'));
      }
    }
    g[0][0] = 'B';
    
    if (n%2 and m%2){
      g[0][m-1] = 'B';
    }

    for (int i = 0; i < n; ++i)
      cout << g[i] << endl;

  }

  return 0;
}
