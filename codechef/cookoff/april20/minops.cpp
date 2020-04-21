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
  string s, r;
  cin >> s >> r;
  int n = sz(s);
  ll l = 0ll;
  ll k = 0ll;
  int i = 0;
  while (i < n){
    if (s[i] != r[i]){
      int len = 0;
      while (i+len < n and s[i+len] != r[i+len])  len++;
      l += len;
      k++;
      i += len+1;
    }
    else{
      i++;
    }
  }
  cout << k << endl;
  cout << l << endl;
  cout << k*l << endl;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
