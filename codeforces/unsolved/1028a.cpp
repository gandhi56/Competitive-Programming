#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

char g[200][200];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  int n,m;
  cin >> n >> m;

  for (int i = 0; i < 200; ++i){
    for (int j = 0; j < 200; ++j){
      g[i][j] = 'W';
    } 
  }

  for (int i = 1; i <= n; ++i){
    cin >> s;
    for (int j = 1; j <= m; ++j)
      g[i][j] = s[j-1];
  }

  int r1, r2, c1, c2;
  for (int i = 1; i <= n; ++i){
    for (int j = 1; j <= m; ++j){
      if (g[i][j] == 'B' and g[i-1][j] == 'W' and g[i][j-1] == 'W'){
        r1 = i;
        c1 = j;
      }
      if (g[i][j] == 'B' and g[i+1][j] == 'W' and g[i][j+1] == 'W'){
        r1 = i;
        c1 = j;
      }
    }
  }

  cout << (r1+r2)/2 << ' ' << (c1+c2)/2 << endl;

  return 0;
}
