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


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n, q;
  cin >> n >> q;

  multiset<int> s;
  for (int i = 0; i < n; ++i){
    int x;
    cin >> x;
    s.insert(x);
  }

  while (q--){
    int k;
    cin >> k;

    if (k >= 1 and k <= n){
      s.insert(k);
    }
    else{
      auto it = s.begin();
      k = -k;
      k--;
      for (int i = 0; i < k; ++i)
        it++;
      s.erase(it);
    }
  }

  if (sz(s) == 0){
    cout << 0 << endl;
  }
  else{
    cout << *s.begin() << endl;
  }

  return 0;
}
