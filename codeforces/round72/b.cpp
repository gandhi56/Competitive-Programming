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

int n, x;
int d[105], h[105];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while (t--){
    cin >> n >> x;

    for (int i = 0; i < n; ++i){
      cin >> d[i] >> h[i];
    }

    int maxd = -2e9;
    int maxdh = -2e9;
    for (int i = 0; i < n; ++i) maxd = max(maxd, d[i]);
    for (int i = 0; i < n; ++i) maxdh = max(maxdh, d[i] - h[i]);

    int res = 1;
    x -= maxd;
    if (x > 0){
      if (maxdh <= 0)
        res = -1;
      else
        res += (x + maxdh - 1) / maxdh;
    }
    cout << res << endl;

  }
  
  return 0;
}
