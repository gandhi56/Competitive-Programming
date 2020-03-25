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

const ll MOD = 998244353;
const int maxn = 200005;
vector<ll> p(maxn, 1);

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n;
  cin >> n;

  for (int i = 1; i < maxn; ++i)
    p[i] = (p[i - 1] * 10) % MOD;

  for (int i = 1; i < n; ++i){
    ll res = 2 * 10 * 9 * p[n - i - 1];
    res += (n - 1 - i) * 10 * 9 * 9 * p[n - i - 2];
    cout << res%MOD << ' ';
  }
  cout << 10 << endl;
  
  
  return 0;
}
