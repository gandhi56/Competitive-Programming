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

int n;
vi x;

int count(int i){
  vector<bool> infect(n, false);
  infect[i] = true;

  int k = i;
  for (int j = i+1; j < n; ++j){
    if (x[j] - x[i] > 2)
      break;

  }

}

void solve(){
  cin >> n;
  x.resize(0);
  x.resize(n);
  for (auto& u : x) cin >> u;

  int minans = INF;
  int maxans = -INF;
  for (int i = 0; i < n; ++i){
    minans = min(minans, count(i));
    maxans = max(maxans, count(i));
  }

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
