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

void solve(int tc){
  int n;
  cin >> n;

  vi h(n);
  for (auto& x : h) cin >> x;

  int cnt = 0;
  for (int i = 1; i < n-1; ++i){
    if (h[i] > h[i-1] and h[i] > h[i+1])    cnt++;
  }
  cout << "Case #" << tc << ": " << cnt << endl;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; ++tc){
    solve(tc);
  }

  return 0;
}
