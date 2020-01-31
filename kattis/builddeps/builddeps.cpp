#define INF 0x3f3f3f3f
#define pb(x) push_back(x)
#define sz(x) (int)(x).size()
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vii;
typedef vector<vector<ii>> viii;

typedef map<string, vector<string>> graph;

void dfs(graph& g, string v, map<string, bool>& visited, vector<string>& ans){
  visited[v] = true;
  for (auto w : g[v])
    if (!visited[w])
      dfs(g, w, visited, ans);
  ans.pb(v);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
    
  graph g;
  int n;
  cin >> n;

  for (int i =0 ; i < n+1; ++i){
    string inp;
    getline(cin, inp);
    string key, w;
    if (inp == "\n")  continue;
    for (auto c : inp){
      if (c == ' '){
        if (w.empty())  continue;
        g[w].pb(key);
        w = "";
      }
      else if (c == ':'){
        key = w;
        w = "";
      }
      else if (c != '\n'){
        w += c;
      }
    }
    if (w.size())
      g[w].pb(key);
  }

  string s;
  cin >> s;

  // toposort
  map<string, bool> visited;
  for (auto it = g.begin(); it != g.end(); ++it){
    visited[it->first] = false;
  }

  vector<string> ans;
  dfs(g, s, visited, ans);
  reverse(ans.begin(), ans.end());
  for (auto s : ans)
    cout << s << endl;

  return 0;
}
