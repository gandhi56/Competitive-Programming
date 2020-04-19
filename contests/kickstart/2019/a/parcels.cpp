#define LIN cout << __LINE__ << endl;
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

int r, c;
string g[300];
int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

bool posok(ii p){
  return p.first >= 0 and p.first < r and p.second >= 0 and p.second < c;
}

int gettime(){
  int dist[r][c];
  for (int row = 0; row < r; ++row)
    for (int col = 0; col < c; ++col)
      dist[row][col] = (g[row][col] == '1'?0:INF);

  int maxdist = 0;
  for (int i = 0; i < r; ++i){
    for (int j = 0; j < c; ++j){
      if (g[i][j] == '0')   continue;
      dist[i][j] = 0;
      queue<ii> q;
      ii curr, next;
      q.push({i, j});
      while (!q.empty()){
        curr = q.front(); q.pop();
        int currdist = dist[curr.first][curr.second];
        maxdist = max(maxdist, currdist);
        for (int i = 0; i < 4; ++i){
          next = {curr.first + dr[i], curr.second + dc[i]};
          if (!posok(next)) continue;
          int nextdist = dist[next.first][next.second];
          if (currdist+1 < nextdist){
            dist[next.first][next.second] = currdist + 1;
            q.push(next);
          }
        }
      }

    }
  }
  
  return maxdist;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt){

    cin >> r >> c;
    for (int i = 0; i < r; ++i)
      cin >> g[i];

    int ans = gettime();
    
    //TODO 
    
    cout << "Case #" << tt << ": " << ans << endl;
  }
  
  return 0;
}





