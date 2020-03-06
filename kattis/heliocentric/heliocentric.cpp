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
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int e, m;
  int t = 1;
  while (cin >> e >> m){
    int n = 0;
    if (e){
      n = 365 - e;
      m = (m + n) % 687;
      e = 0;
    }
    while (m){
      m = (m + 365) % 687;
      n += 365;
    }
    cout << "Case " << t++ << ": " << n << endl;
  }
  return 0;
}
