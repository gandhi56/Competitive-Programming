#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

typedef long double ld;

int g[3][3];
ld len = 0.0;

inline ld sq(ld x){   return x*x;   }

ld dist(ii a, ii b){
  return sqrt( sq(a.first - b.first) + sq(a.second - b.second) );
}

ii find(int num){
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      if (g[i][j] == num) return {i,j};
}

ld solve(ii p){
  int nextVal = g[p.first][p.second] + 1;
  ii p2 = find(nextVal);
  len += dist(p, p2);
  if (nextVal < 9)
    return solve(p2);
  return len;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      cin >> g[i][j];

  cout << fixed << setprecision(8);
  cout << solve(find(1)) << endl;

  return 0;
}
