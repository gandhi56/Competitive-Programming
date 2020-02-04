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
  
  int n, k;
  cin >> n >> k;

  int a[n+1];
  a[0] = 0;
  for (int i=1; i <= n; ++i) cin >> a[i];

  sort(a, a+n);
  cout << (a[k-1] == a[k]? -1 : a[k-1]+1) << endl;
  return 0;
}
