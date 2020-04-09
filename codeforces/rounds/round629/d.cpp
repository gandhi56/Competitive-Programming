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

int n;
vi t;
vi c;

bool same_type(){
  for (auto x : t)
    if (x != t[0])
      return false;
  return true;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int q;
  cin >> q;
  while (q--){
    cin >> n;
    t.assign(n, 0);
    c.assign(n, 0);
    for (auto& x : t)   cin >> x;
    if (same_type()){
      cout << 1 << endl;
      for (int i = 0; i < n; ++i)   cout << 1 << ' ';
      cout << endl;
      continue;
    }
    if (n%2 == 0){
      cout << 2 << endl;
      for (int i = 0; i < n; ++i)
        cout << (i&1?1:2) << ' ';
      cout << endl;
      continue;
    }
    // bug in the below case
    int cnt = 0;
    for (int i = 0; i < n; ++i)
      if (t[i] == t[(i+1)%n])
        cnt++;
    if (cnt == 1){
      cout << 2 << endl;
      for (int i = 0; i < n; ++i)
        cout << (i&1?1:2) << ' ';
      cout << endl;
      continue;
    }
    cout << 3 << endl;
    cout << 3 << ' ';
    for (int i = 1; i < n; ++i)
      cout << (i&1?1:2) << ' ';
    cout << endl;
  }

  return 0;
}
