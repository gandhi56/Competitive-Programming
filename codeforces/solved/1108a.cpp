#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> bnd = {a, b, c, d};
    for (auto x : bnd){
      for (auto y : bnd){
        if (a <= x and x <= b and c <= y and y <= d and x != y){
          cout << x << ' ' << y << endl;
          goto done;
        }
      }
    }
    cout << "0 0" << endl;
done:;
  }
  return 0;
}
