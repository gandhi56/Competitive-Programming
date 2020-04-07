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
  
  int n;
  cin >> n;

  vector<pair<ll, ll>> mines;
  for (int i =0 ; i <n ; ++i){
    ll x, y;
    cin >> x >> y;
    mines.emplace_back(x, y);
  }

  ll minx = 1e10, miny = 1e10;
  ll maxx = -1e10, maxy = -1e10;
  for (auto& m : mines){
    minx = min(minx, m.first);
    maxx = max(maxx, m.first);
    miny = min(miny, m.second);
    maxy = max(maxy, m.second);
  }
  ll d = max(maxx - minx, maxy - miny);
  cout << d*d << endl;

  return 0;
}
