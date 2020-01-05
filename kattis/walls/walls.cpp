#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

double sq(double a){
  return a*a;
}

bool reachable(double x, double y, double xx, double yy, double r){
  return sq(x - xx) + sq(y - yy) <= sq(r);
}

int main(){
  double l, w, r;
  int n;
  cin >> l >> w >> n >> r;

  double cx[] = {-l/2, l/2, 0, 0};
  double cy[] = {0,0,-w/2, w/2};

  double x[n], y[n];
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

  vector<int> targ(n);

  for (int i = 0; i < n; ++i){
    int val = 0;
    for (int j = 0; j < 4; ++j){
      if (reachable(x[i], y[i], cx[j], cy[j], r))
        val |= (1<<j);
    }
    targ[i] = val;
  }

  vector<int> cranes;
  for (int i = 0; i < n; ++i){
    bool ok = true;
    for (auto j : cranes){
      if (targ[i] == targ[j]){
        ok = false;
        break;
      }
    }
    if (ok) cranes.push_back(i);
  }

  int ans = INF;
  for (int m = 1; m < (1<<(int)cranes.size()); ++m){
    if (__builtin_popcount(m) > 4)  continue;
    int val = 0;
    int cnt = 0;
    for (int k = 0; k < (int)cranes.size(); ++k){
      if (m&(1<<k)){
        val |= targ[cranes[k]];
        cnt++;
      }
      if (__builtin_popcount(val)==4) break;
    }
    if (__builtin_popcount(val) == 4){
      ans = min(ans, cnt);
    }
  }

  if (ans == INF){
    cout << "Impossible" << endl;
  }
  else{
    cout << ans << endl;
  }


  return 0;
}
