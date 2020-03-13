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
vector<string> grid(7);
vector<string> m(7);
vi ships(7);
int ans = 0;

int dr[] = {0,1};
int dc[] = {1,0};

void show_m(){
  for (auto x : m)  cout << x << endl;
}

void show_grid(){
  for (auto x : grid)   cout << x << endl;
}

bool place(int i, int r, int c, int o){
  if ((!o and c + ships[i] > n) or (o and r + ships[i] > n))
    return false;
  
  for (int j = 0; j < ships[i]; ++j){
    if (o){
      if (m[r+j][c] != '?') return false;
    }
    else{
      if (m[r][c+j] != '?') return false;
    }
  }

  for (int j = 0; j < ships[i]; ++j){
    if (o and grid[r+j][c] == 'O'){ // vertical
      return false;
    }
    else if (!o and grid[r][c+j] == 'O'){
      return false;
    }
  }

  for (int j = 0; j < ships[i]; ++j){
    if (o){ // vertical
      m[r+j][c] = '0'+i;
    }
    else{
      m[r][c+j] = '0'+i;
    }
  }
  return true;
}

void kill(int i, int r, int c, int o){
  for (int j = 0; j < ships[i]; ++j){
    if (o){ // vertical
      m[r+j][c] = '?';
    }
    else{
      m[r][c+j] = '?';
    }
  }
}

bool check_hits(){
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (grid[i][j]=='X' and m[i][j]=='?')
        return false;
  return true;
}

bool battle(int i){
  if (i == k){
    if (check_hits()){
      return true;
    }
    return false;
  }
  for (int r = 0; r < n; ++r){
    for (int c = 0; c < n; ++c){
      if (place(i, r, c, 0)){
        if (battle(i+1)){
          ans++;
          cout << endl;
          show_m();
          cout << endl;
        }
        kill(i, r, c, 0);
      }

      if (place(i, r, c, 1)){
        if (battle(i+1)){
          ans++;
          cout << endl;
          show_m();
          cout << endl;
        }
        kill(i, r, c, 0);
      }
    }
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  
  grid.resize(n);
  ships.resize(k);
  m.resize(n);
  for (auto& x : grid) cin >> x;
  for (auto& x : ships) cin >> x;
  for (auto& x : m)
    for (int i = 0; i < n; ++i)
      x += "?";

  battle(0);
  cout << ans << endl;

  return 0;
}
