#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, k;
int m[100][100];

void show(){
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j)
      cout << m[i][j] << ' ';
    cout << endl;
  }
}

int trace(){
  int tr = 0;
  for (int i = 0; i < n; ++i) tr += m[i][i];
  return tr;
}

bool getIdx(int& r, int& c){
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j){
      if (m[i][j] == -1){
        r = i;
        c = j;
        return 1;
      }
    }
  }
  return 0;
}

bool used(int row, int col, int k){
  for (int i = 0; i < n; ++i)
    if (m[i][col] == k or m[row][i] == k)
      return true;
  return false;
}

bool cp(){
  int r, c;
  if (!getIdx(r, c)){
    if (trace() == k){
      return true;
    }
    return false;
  }

  for (int k = 1; k <= n; ++k){
    if (used(r, c, k))  continue;
    m[r][c] = k;
    if (cp())   return true;
    m[r][c] = -1;
  }
  return false;
}


void solve(int tc){
  memset(m, -1, sizeof(m));
  cin >> n >> k;
  cout << "Case #" << tc << ": ";
  if (cp()){
    cout << "POSSIBLE" << endl;
    show();
  }
  else
    cout << "IMPOSSIBLE" << endl;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; ++tc)
    solve(tc);

  return 0;
}
