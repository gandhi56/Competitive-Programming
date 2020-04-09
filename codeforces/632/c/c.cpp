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

const ll MAXN = 2*100000;
const int K = 25;

ll st[MAXN][K+1];
int n;
ll a[MAXN];

ll sum(int l, int r){
  ll tot = 0;
  for (int j = K; j >= 0; j--){
    if ((1<<j) <= r - l + 1){
      tot += st[l][j];
      l += (1<<j);
    }
  }
  return tot;
}

ll solve(int i, int j){
  cout << "running " << i << ' ' << j << endl;
  if (i == j){
    return (a[i] == 0? 0 : 1);
  }
  int m = (j-i)/2;

  ll leftsum = sum(i, m);
  ll rightsum = sum(m+1, j);

  if (leftsum == 0 or rightsum == 0){
    return 0;
  }

  ll left = solve(i, m);
  ll right = solve(m+1, j);
  ll fullsum = sum(i, j);
  ll ans = left + right;
  if (fullsum != 0)
    ans++;
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i= 0; i < n; ++i)    cin >> a[i];

  for (int i =0 ; i < n; ++i)
    st[i][0] = a[i];
  for (int j = 1; j <= K; ++j){
    for (int i = 0; i + (1<<j) <= n; ++i)
      st[i][j] = st[i][j-1] + st[i+ (1<<(j-1))][j-1];
  }

  ll cnt = solve(0, n-1);
  cout << cnt << endl;


  return 0;
}
