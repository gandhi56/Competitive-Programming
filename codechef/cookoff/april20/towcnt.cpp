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

struct seg{
  int a, b, c, d;
};

void solve(){
  int h, n;
  cin >> h >> n;

  vector<seg> lines;
  for (int i =0 ; i < n; ++i){
    int t, x, a;
    cin >> t >> x >> a;
    if (t == 0){
      lines.emplace_back(x, 0, x, a);
    }
    else{
      lines.emplace_back(x, h, x, a);
    }
  }

  for (int i = 0; i < n; ++i){
    for ()
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
