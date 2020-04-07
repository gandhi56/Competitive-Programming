#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define max(a, b, c) max(a, max(b, c))
#define min(a, b, c) min(a, min(b, c))
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
char g[1005][1005];
int ax, ay;
int bx, by;
int cx, cy;

bool ok(pii p){
  return p.first >= 1 and p.first <= n and p.second >= 1 and p.second <= n;
}

bool inatk(pii p){
  if (p.first == ay or p.second == ax)  return true;
  if (abs(p.first - ay) == abs(p.second - ax))  return true;
  return false;
}

string bfs(){
  pii curr = {by, bx};
  if (inatk(curr))  return "NO";
  int dist[n+1][n+1];
  memset(dist, INF, sizeof(dist));
  queue<pii> q;
  q.push(curr);
  dist[curr.first][curr.second] = 0;
  while (!q.empty()){
    curr = q.front(); q.pop();
    
    //cout << curr.first << ' ' << curr.second << endl;

    if (curr.first == cy and curr.second == cx) return "YES";
    for (int dx : {0, 0, 1, -1, 1, -1, -1, 1}){
      for (int dy : {1, -1, 0, 0, 1, -1, 1, -1}){
        pii next = {curr.first + dy, curr.second+dx};
        if (dist[next.first][next.second] != INF)   continue;
        if (!ok(next) or inatk(next))  continue;
        q.push(next);
        dist[next.first][next.second] = dist[curr.first][curr.second] + 1;
      }
    }
  }
  return "NO";
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  cin >> n;
  cin >> ax >> ay;
  cin >> bx >> by;
  cin >> cx >> cy;

  cout << bfs() << endl;


  return 0;
}








