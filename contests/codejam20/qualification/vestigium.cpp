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

int n;
int m[200][200];

void solve(int t){
  int tr = 0;
  for (int i = 1; i <= n; ++i)  tr += m[i][i];

  int r = 0;
  int c = 0;
  
  for (int i = 1; i <= n; ++i){
    set<int> seen;
    for (int j = 1; j <= n; ++j){
      if (seen.find(m[i][j]) != seen.end()){
        r++;
        break;
      }
      seen.insert(m[i][j]);
    }
  }

  for (int i = 1; i <= n; ++i){
    set<int> seen;
    for (int j = 1; j <= n; ++j){
      if (seen.find(m[j][i]) != seen.end()){
        c++;
        break;
      }
      seen.insert(m[j][i]);
    }
  }

  cout << "Case #" << t << ": " << tr << " " << r << " " << c << endl;

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; ++tc){
    cin >> n;

    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        cin >> m[i][j];

    solve(tc);

  }

  return 0;
}
