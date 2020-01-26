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

void show(vector<string> v){
  for (auto x : v)  cout << x << endl;
}

ii find(vector<string> g){
  for (int i =1 ; i < g.size()-1; ++i){
    for (int j =1; j < g.size()-1; ++j){
      if (g[i][j] == '?') return {i,j};
    }
  }
  return {-1,-1};
}

bool unk(char c){
  return c=='.' or c=='?';
}

bool ok(vector<string> g, char c, ii x){
  char nbrs[] = {g[x.first+1][x.second],
                 g[x.first-1][x.second],
                 g[x.first][x.second+1],
                 g[x.first][x.second-1] };
  
  if (c == 'G'){
    return unk(nbrs[0]) and unk(nbrs[1]) and unk(nbrs[2])  and unk(nbrs[3]);
  }
  else{
    return (unk(nbrs[0]) or nbrs[0]==c) and (unk(nbrs[1]) or nbrs[1]==c) and
          (unk(nbrs[2]) or nbrs[2]==c) and (unk(nbrs[3]) or nbrs[3]==c);
  }

  return false;
}

int solve(vector<string> g){
  ii x = find(g);
  if (x.first == -1 and x.second == -1)  return 1;
  int count = 0;
  for (char c : {'B', 'G', 'P'}){
    if (ok(g, c, x)){
      g[x.first][x.second] = c;
      count += solve(g);
      g[x.first][x.second] = '?';
    }
  }
  return count;
}

bool triv(vector<string> g){
  for (auto x : g){
    if (x.find('?') != -1)  return false;
  }
  return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while (t--){
      int n;
      cin >> n;

      vector<string> g;
      string s;
      string blk;
      for (int i = 0; i < n+2; ++i) blk += '.';
      g.pb(blk);
      for (int i = 0; i < n; ++i){
        cin >> s;
        g.pb("."+s+".");
      }
      g.pb(blk);

      if (triv(g)){
        cout << 0 << endl;
        continue;
      }

      cout << solve(g) << endl;
    }
    
    return 0;
}
