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

vector<vi> t;
vi d, p;
vector<bool> seen, isblack;

void dfs(int u, int depth){
  d[u] = depth;
  seen[u] = true;
  for (auto& v : t[u])
    if (!seen[v]){
      p[v] = u;
      dfs(v, depth+1);
    }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n, k;
  cin >> n >> k;
  
  t.resize(n);
  d.resize(n);
  p.resize(n);
  seen.assign(n, false);
  isblack.assign(n, false);
  for (int i = 0; i < n-1; ++i){
    int x, y;
    cin >> x >> y;
    t[--x].push_back(--y);
    t[y].push_back(x);
  }

  p[0] = 0;
  dfs(0, 0);

  vi nodes;
  for (int i =0 ; i < n; ++i)   nodes.push_back(i);

  sort(all(nodes), [](int i, int j){
        if (d[i] == d[j])   return i < j;
        return d[i] > d[j];
      });

  for (int i = 0; i < k; ++i)
    isblack[nodes[i]] = true;

  //for (int u = 0; u < n; ++u)
  //  cout << u+1 << ' ' << isblack[u] << endl;

  int ans =0 ;
  for (int u = 0; u < n; ++u){
    if (!isblack[u])    continue;
    int v = u;
    while (1){
      if (!isblack[v])  ans++;
      if (v == 0)   break;
      v = p[v];
    }
  }
  cout << ans << endl;

  return 0;
}


