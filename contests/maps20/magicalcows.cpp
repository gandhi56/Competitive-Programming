#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void f(vi& c, int C){
  for (int i = 0; i < sz(c); ++i){
    int x = c[i] << 1;
    if (x <= C){
      c[i] = x;
    }
    else{
      c[i] = ceil(x/2);
      c.push_back(x/2);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int C, n, m;
  cin >> C >> n >> m;
  vi c(n);
  for (auto& x : c) cin >> x;

  LIN;
  vi ans(m+1);
  for (int i = 0; i < m; ++i){
    f(c, C);
    ans[i] = sz(c);
    cout << i << ' ' << ans[i] << endl;
  }
  LIN;

  while (m--){
    int d;
    cin >> d;
    cout << ans[d] << endl;
  }

  return 0;
}
