#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

char g[120][120];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i){
    string s;
    cin >> s;
    for (int j = 1; j <= m; ++j){
      g[i][j] = s[j-1];
    }
  }

  int r0 = 120, r1=-1, c0 = 120, c1 = -1;
  for (int i = 1; i <= n; ++i){
    for (int j = 1; j <= m; ++j){
      if (g[i][j] == 'B'){
        r1 = max(r1, i);
        c1 = max(c1, j);
        r0 = min(r0, i);
        c0 = min(c0, j);
      }
    }
  }

  cout << (r1+r0)/2 << ' ' << (c1+c0)/2 << endl;


  return 0;
}
