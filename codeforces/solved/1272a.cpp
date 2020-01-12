#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> q;
  while (q--){
    int a, b, c;
    cin >> a >> b >> c;
    int ans = INT_MAX;
    for (int ap : {a-1, a, a+1}){
      for (int bp : {b-1, b, b+1}){
        for (int cp : {c-1, c, c+1}){
          ans = min(ans, abs(ap-bp) + abs(ap-cp) + abs(bp-cp));
        }
      }
    }
    cout << ans << endl;
  }
  
  return 0;
}
