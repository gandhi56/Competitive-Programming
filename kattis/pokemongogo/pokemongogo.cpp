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

struct state{
  int dist, sub, idx;
  bool operator<(const state& s) const {
    if (dist == s.dist){
      if (sub == s.sub){
        return idx < s.idx;
      }
      return sub < s.sub;
    }
    return dist < s.dist;
  }
};

int getDist(ii a, ii b){
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n;
  cin >> n;
 
  vector<ii> pos;
  map<string, int> pok;
  vi msk(n);
  int s = 0;
  for (int i = 0; i < n; ++i){
    int x, y;
    string name;
    cin >> x >> y >> name;
    pos.push_back({x, y});
    if (pok.find(name) == pok.end()){
      pok[name] = 1<<s;
      s++;
    }
    msk[i] = pok[name];
  }

  pos.push_back({0,0});
  msk.pb(0);

  int gdist[n+1][n+1];
  for (int i =0 ; i < n+1; ++i){
    for (int j = 0; j < n+1; ++j){
      gdist[i][j] = getDist(pos[i], pos[j]);
    }
  }

  vii dist;
  dist.resize((1<<s), vi(n+1, INF));
  dist[0][n] = 0;
  set<state> states;

  states.insert({0,0,n});
  while (!states.empty()){
    int currn = states.begin()->idx;
    int currs = states.begin()->sub;
    states.erase(states.begin());

    for (int i = 0; i <= n; ++i){
      int nextn = i;
      int nexts = currs | msk[i];
      int wt = gdist[currn][nextn];
      if (dist[nexts][nextn] > dist[currs][currn] + wt){
        states.erase({dist[nexts][nextn], nexts, nextn});
        dist[nexts][nextn] = dist[currs][currn] + wt;
        states.insert({dist[nexts][nextn], nexts, nextn});
      }
    }

  }
  cout << dist[(1<<s)-1][n] << endl;

  return 0;
}










