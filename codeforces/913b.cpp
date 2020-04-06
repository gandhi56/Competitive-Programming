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
vector<vi> g;

bool solve(int i){
  if (sz(g[i]) == 0)    return true;
  if (i == 0){
    for (auto j : g[i])
      if (!solve(j))
        return false;
    return true;
  }
  else{
    if (sz(g[i]) == 3){
      for (auto j : g[i])
        if (!solve(j))
          return false;
      return true;
    }
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  cin >> n;
  g.resize(n);
  for (int i = 0; i < n-1; ++i){
    int j;
    cin >> j;
    if (i == 0 and j == 1)  continue;
    g[--j].push_back(i);
  }

  cout << (solve(0)?"Yes":"No") << endl;

  return 0;
}
