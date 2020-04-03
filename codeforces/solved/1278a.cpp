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

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while (t--){
    string p;
    cin >> p;

    string h;
    cin >> h;

    int n = sz(h);
    vi cnt(26);
    for (int i = 0; i < sz(p); ++i)
      ++cnt[p[i] - 'a'];
    bool found = false;
    for (int i = 0; i < n; ++i){
      vi tst(26);
      for (int j = i; j < n; ++j){
        ++tst[h[j] - 'a'];
        if (cnt == tst){
          found = true;
          goto FND;
        }
      }
    }

FND:;
    cout << (found? "YES" : "NO") << endl;

  }
  
  return 0;
}
