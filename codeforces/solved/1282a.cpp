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
    int a, b, c, r;
    cin >> a >> b >> c >> r;
    cout << abs(b-a) - max(0, min(c+r, max(a, b)) - max(c-r, min(a,b)))<< endl;
  }
  
  return 0;
}
