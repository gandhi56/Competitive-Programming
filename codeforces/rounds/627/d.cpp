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

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n;
  cin >> n;

  ll cnt = 0;
  vi a(n), b(n);
  for (auto& x : a) cin >> x;
  for (auto& x : b) cin >> x;

  vi diff(n);
  for (int i = 0; i < n; ++i)  diff[i] = a[i] - b[i];

  sort(diff.begin(), diff.end());

  for (int i = 0; i < n; ++i){
    if (diff[i] <=  0) continue;
    int pos = lower_bound(diff.begin(), diff.end(), -diff[i] + 1) - diff.begin();
    cnt += i - pos;
  }

  cout << cnt << endl;

  return 0;
}
