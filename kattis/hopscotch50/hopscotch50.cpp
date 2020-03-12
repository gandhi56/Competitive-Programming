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

int n, k;
int mat[52][52];
viii pos;

int getDist(ii a, ii b){
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int dijkstra(int i, int j){
  int dist[n][n];
  memset(dist, INF, sizeof(dist));
  dist[i][j] = 0;
  priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
  pq.push({0, {i, j}});
  while (!pq.empty()){
    auto edge = pq.top(); pq.pop();
    ii curr = edge.second;
    int nextVal = mat[curr.first][curr.second] + 1;
    if (nextVal == k+1)
      return edge.first;
    for (auto next : pos[nextVal]){
      int wt = getDist(curr, next);
      if (dist[next.first][next.second] > dist[curr.first][curr.second] + wt){
        dist[next.first][next.second] = dist[curr.first][curr.second] + wt;
        pq.push(make_pair(dist[next.first][next.second], next));
      }
    }
  }

  return INF;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  cin >> n >> k;

  pos.resize(k+1);
  pos[0].push_back({-1, -1});
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n ;++j){
      cin >> mat[i][j];
      pos[mat[i][j]].push_back({i,j});
    }
  }

  int ans = INF;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j){
      if (mat[i][j] != 1)   continue;
      ans = min(ans, dijkstra(i, j));
    }
  }

  cout << (ans == INF? -1 : ans) << endl;

  return 0;
}
