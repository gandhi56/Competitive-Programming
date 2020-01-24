#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

struct crane{
  int x, y, r;
};

inline int sq(int x){
  return x*x;
}

bool crash(crane i, crane j){
  return ( sqrt(sq(i.x - j.x) + sq(i.y - j.y)) ) <= i.r+j.r;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while (t--){
    int c;
    cin >> c;
    crane cr[c];
    for (int i = 0; i < c; ++i) cin >> cr[i].x >> cr[i].y >> cr[i].r;

    int ans = 0;
    for (int m = 0; m < (1<<c); ++m){
      int area = 0;
      // check for any conflict
      for (int i = 0; i < c; ++i){
        for (int j = i+1; j < c; ++j){
          if (m&(1<<i) and m&(1<<j) and crash(cr[i], cr[j])){
            goto done;
          }
        }
      }

      // if no crash, sum areas
      for (int i = 0; i < c; ++i){
        if (m&(1<<i)){
          //cout << "-->" << cr[i].x << ' ' << cr[i].y << endl;
          area += cr[i].r*cr[i].r;
        }
      }

      //cout << area << endl;
      ans = max(ans, area);

      done:;
    
      //cout << endl;

    }
    cout << ans << endl;

  }
  
  return 0;
}
