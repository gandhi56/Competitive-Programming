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

  vector<ll> b(n), a(n);
  for (auto& bb : b)    cin >> bb;

  a[0] = b[0];
  
  ll m = max(a[0], 0ll);
  a[1] = b[1] + m;
  for (int i = 2; i < n; ++i){
    m = max(m, a[i-1]);
    a[i] = b[i] + m;
  }

  for (auto x : a)  cout << x << ' ';
  cout << endl;
  
  return 0;
}
