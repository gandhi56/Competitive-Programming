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

int manDist(ii a, ii b){
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n, k;
  cin >> n >> k;
  

  int g[n][n];
  vector< vector<ii> > cells(k+1);
  int x;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j){
      cin >> x;
      g[i][j] = x;
      cells[x].push_back({i, j});
    }
  }
  
  int d[n][n];
  memset(d, INF, n*n*sizeof(int));

  priority_queue<pair<int, ii>, vector< pair<int, ii> >, greater< pair<int, ii> > > pq;
  pq.push({0, {-1, -1}});
  while (!pq.empty()){
    auto x = pq.top(); pq.pop();
    int dist = x.first;
    ii currPos = x.second;
    if (currPos.first == -1){
      
    }
    int val = (currPos.first == -1 ? 0 : g[currPos.first][currPos.second]);

    for (auto& nextPos : cells[val+1]){
      int wt = manDist(currPos, nextPos);
      if (d[currPos.first][currPos.second] + wt < d[nextPos.first][nextPos.second]){
        d[nextPos.first][nextPos.second] = d[currPos.first][currPos.second] + wt;
        pq.push({d[nextPos.first][nextPos.second], nextPos});
      }
    }
  }

  cout << "term" << endl;

  return 0;
}
