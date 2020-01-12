#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  string s[n];
  string t[m];
  for (int i = 0; i < n; ++i) cin >> s[i];
  for (int i = 0; i < m; ++i) cin >> t[i];

  int q;
  cin >> q;
  while (q--){
    int y ;
    cin >> y;

    y--;

    cout << s[y%n] + t[y%m] << endl;

  }
  
  return 0;
}
