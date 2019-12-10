
#define MAXN 1004

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

enum dir{RIGHT, UP, LEFT, DOWN};

typedef pair<int,int> ii;

int grid[MAXN][MAXN];

void spiral(int i, int j, int val, dir d, int cnt){
  if (i >= MAXN or i < 0 or j >= MAXN or j < 0) return;
  int dr = 1, dc = 0;
  dir nextdir = RIGHT;
  int nextcnt = cnt;
  if (d == RIGHT){
    dr = 0;
    dc = 1;
    nextdir = UP;
  }
  else if (d == LEFT){
    dr = 0;
    dc = -1;
    nextdir = DOWN;
  }
  else if (d == UP){
    dr = -1;
    dc = 0;
    nextdir = LEFT;
    nextcnt = cnt+1;
  }
  else if (d == DOWN){
    dr = 1;
    dc = 0;
    nextdir = RIGHT;
    nextcnt = cnt+1;
  }

  for (int k = 0; k < cnt; ++k){
    grid[i][j] = val++;
    i += dr;
    j += dc;
  }
  grid[i][j] = val;

  if (val == MAXN)  return;

  spiral(i, j, val, nextdir, nextcnt);

}

void show_spiral(int R, int C){
  for (int i = 0; i < R; ++i){
    for (int j = 0; j < C; ++j){
      cout << grid[i][j] << '\t';
    }
    cout << endl;
  }
}

inline bool bad(int p){
  return p < 0 or p >= MAXN;
}

int main(){
  
  // construct grid
  spiral(MAXN/2, MAXN/2, 1, RIGHT, 1);

  // sieve all primes
  int n = 10001;
  bool isprime[n+1];
  memset(isprime, true, n+1);
  isprime[0] = isprime[1] = false;
  for (int d = 2; d <= n; ++d){
    if (isprime[d]){
      for (int i = 2; d*i <= n; ++i)
        isprime[d*i] = false;
    }
  }

  int x, y;
  int tt = 1;
  while (cin >> x >> y){
    if (isprime[x] or isprime[y]){
      cout << "Case " << tt++ << ": impossible" << endl;
      continue;
    }

    int dist[MAXN][MAXN];
    for (int i = 0; i < MAXN; ++i){
      for (int j = 0; j < MAXN; ++j){
        dist[i][j] = -1;
      }
    }

    ii xx;
    bool foundX = false;
    for (int i = 0; i < MAXN and !foundX; ++i){
      for (int j = 0; j < MAXN and !foundX; ++j){
        if (grid[i][j] == x){
          xx = {i,j};
          foundX = true;
        }
      }
    }

    int ans = -1;
    ii adj[] =  { {1,0}, {0,1}, {-1,0}, {0,-1} };
    queue<ii> q;
    int cnt = 0;
    q.push(xx);
    dist[xx.first][xx.second] = 0;
    while (!q.empty()){
      xx = q.front(); q.pop();
      if (grid[xx.first][xx.second] == y){
        ans = dist[xx.first][xx.second];
        break;
      }
      for (ii adj : adj){
        ii next = {xx.first + adj.first, xx.second + adj.second};
        if (bad(next.first) or bad(next.second))      continue;
        if (dist[next.first][next.second] >= 0)         continue;
        if (isprime[ grid[next.first][next.second] ]) continue;
        q.push(next);
        dist[next.first][next.second] = dist[xx.first][xx.second] + 1;
      }
    }

    if (ans == -1){
      cout << "Case " << tt++ << ": impossible" << endl;
    }
    else{
      cout << "Case " << tt++ << ": " <<  ans << endl;
    }

  }

  return 0;
}
