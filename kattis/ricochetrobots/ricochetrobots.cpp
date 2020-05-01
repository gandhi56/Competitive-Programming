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

int n, w, h, l;
vector<string> grid;
map<char, pii> pos;

bool ok(pii p){
  return p.first >= 0 and p.first < h and p.second >= 0 and p.second < w;
}

int count(pii dpos){
  int len = 0;
  pii pp = pos['X'];
  pp.first += dpos.first;
  pp.second += dpos.second;
  while (ok(pp)){
    if (grid[pp.first][pp.second] == 'W'){
      break;
    }
    else{
      pp.first += dpos.first;
      pp.second += dpos.second;
      len++;
    }
  }
  return len;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  cin >> n >> w >> h >> l;

  for (int i = 0; i < h; ++i){
    string s;
    cin >> s;
    grid.push_back(s);
  }

  for (int i = 0; i < h; ++i){
    for (int j = 0; j < w; ++j){
      if (grid[i][j] != 'W' and grid[i][j] != '.'){
        pos[grid[i][j]] = {i, j};
      }
    }
  }


  int minSup = h;
  for (int dx : {1, -1, 0, 0}){
    for (int dy : {0, 0, 1, -1}){
      if (dx != 0 and dy != 0)  continue;
      if (dx == 0 and dy == 0)  continue;
      int cnt = count({dx, dy});
      if (cnt>0)
        minSup = min(minSup, cnt);
    }
  }

  cout << minSup << endl;
  
  return 0;
}
