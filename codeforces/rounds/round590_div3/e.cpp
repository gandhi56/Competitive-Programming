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
  
  string s;
  cin >> s;

  vector< set<int> > pos(26);
  for (int i = 0; i < sz(s); ++i)
    pos[s[i] - 'a'].insert(i);
  
  int q;
  cin >> q;
  while (q--){
    int t;
    cin >> t;
    if (t == 1){
      int i;
      char c;
      cin >> i >> c;
      --i;
      pos[s[i] - 'a'].erase(i);
      s[i] = c;
      pos[s[i] - 'a'].insert(i);
    }
    else{
      int l, r;
      cin >> l >> r;
      --l; --r;
      int cnt = 0;
      for (int c = 0; c < 26; ++c){
        auto it = pos[c].lower_bound(l);
        if (it != pos[c].end() and *it <= r)    ++cnt;
      }
      cout << cnt << endl;
    }
  }
  
  return 0;
}
