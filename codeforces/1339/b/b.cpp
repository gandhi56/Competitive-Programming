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

void solve(){
  int n;
  cin >> n;

  vi a(n);
  for (auto& x : a) cin >> x;

  sort(all(a));

  vi ans;
  int inc = 0;
  for (int i = n/2;;){
    if (i < 0 or i >= n)  break;
    ans.push_back(a[i]);
    i += inc;
    if (inc>0)
      inc = -(inc+1);
    else
      inc = -(inc-1);
  }
  for (auto x : a)  cout << x << ' ';
  cout << endl;

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while (t--){
    solve();
  }
  
  return 0;
}
