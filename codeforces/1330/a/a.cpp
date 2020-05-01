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

  int t;
  cin >> t;

  while (t--){
    int n, x;
    cin >> n >> x;

    set<int> s;
    for (int  i= 0; i < n; ++i){
      int u;
      cin >> u;
      s.insert(u);
    }

    int v;
    for (v = 1; v < 2000; ++v){
      int k = x;
      for (int i = 1; i <= v; ++i){
        if (s.find(i) == s.end()){
          if (k == 0) {
            cout << v-1 << endl;
            goto done;
          }
          else{
            k--;
          }
        }
      }
    }
    done:;

  }

  return 0;
}
