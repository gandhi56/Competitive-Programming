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

bool islucky(int x){
  while (x){
    int d = x % 10;
    if (d != 4 and d != 7)
      return false;
    x /= 10;
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string ans = "NO";
  for (int d = 1; d <= n; ++d){
    if (n%d == 0 and islucky(d)){
      ans = "YES";
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
