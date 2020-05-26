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
#define sq(x) (int)(x*x)
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--){
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (auto& aa : a)  cin >> aa;

    string s = a[0];

    vector<map<char, int>> v(m);
    for (int i = 0; i < m; ++i){
      for (int j = 0; j < n; ++j){
        v[i][a[j][i]]++;
      }
    }

    for (int i = 0; i < m; ++i){
      for (auto p : v[i]){
        if (p.second > v[i][s[i]]){
          s[i] = p.first;
        }
      }
    }

    cout << s << endl;

  }

  return 0;
}
