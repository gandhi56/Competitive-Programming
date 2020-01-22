#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

struct pos{
  int x, y;
  bool operator<(const pos& p)const{
    if (x == p.x) return  y < p.y;
    return x < p.x;
  }
};

bool can_reach(pos p1, pos p2){
  return p2.y >= p1.y and p2.x >= p1.x;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;

    vector<pos> pkg;
    while (n--){
      pos p;
      cin >> p.x >> p.y;
      pkg.push_back(p);
    }

    sort(pkg.begin(), pkg.end());

    pos curr{0,0};
    int i = 0;
    string ans = "";
    while (i < pkg.size()){
      // can I reach next pkg
      if (!can_reach(curr, pkg[i])){
        cout << "NO" << endl;
        goto done;
      }

      int k = pkg[i].x - curr.x;
      while (k--) ans += "R";
      k = pkg[i].y - curr.y;
      while (k--) ans += "U";

      curr.x = pkg[i].x;
      curr.y = pkg[i].y;
      i++;
    }
    cout << "YES" << endl << ans << endl;
    done:;
  }
  
  return 0;
}
