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

const int maxn = 50000;

ll len;
ll p[maxn];

void prefix(ll a, ll b){
  len = a*b;
  p[0] = 0;
  for (int i = 1; i <= len; ++i){
    p[i] = p[i-1];
    if ((i % a) % b != (i % b) % a)
      p[i]++;
  }
}

ll query(ll l){
  ll cnt = l / len;
  ll rem = l % len;
  return p[len] * cnt + p[rem];
}

void solve(){
  ll a, b, q;
  cin >> a >> b >> q;

  prefix(a, b);

  while (q--){
    ll l, r;
    cin >> l >> r;
    cout << query(r) - query(l-1) << ' ';
  }
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
