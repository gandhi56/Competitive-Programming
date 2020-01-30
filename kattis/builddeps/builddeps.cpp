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

int id;

void dfs(map<string, vector<string>>& g, string x, map<string, bool>& seen, vector<string>& top){
  seen[x] = true;
  for (auto s : g[x]){
    if (!seen[s]){
      dfs(g, s, seen, top);
    }
  }
  top.pb(x);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
    
  map<string, vector<string>> g;
  int n;
  cin >> n;

  for (int i =0 ; i < n+1; ++i){
    string inp;
    getline(cin, inp);
    string key, w;
    for (auto c : inp){
      if (c == ' '){
        g[key].pb(w);
        w = "";
      }
      else if (c == ':'){
        key = w;
        g.insert({key, vector<string>()});
        w = "";
      }
      else{
        w += c;
      }
    }
    g[key].pb(w);
  }

  string s;
  cin >> s;

  // toposort
  map<string, bool> seen;
  for (auto it = g.begin(); it != g.end(); ++it){
    seen[it->first] = false;
  }

  vector<string> top;

  id = n-1;
  
  for (auto it = g.begin(); it != g.end(); ++it){
    if (!seen[it->first])
      dfs(g, it->first, seen, top);
  }

  for (auto s : top)  cout << s << endl;

  return 0;
}
