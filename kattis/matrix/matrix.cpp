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
  
  int t = 1;
  int a, b, c, d;
  while (cin >> a >> b >> c >> d){
    double coeff = 1/(a*d - c*b);
    cout << "Case " << t++ << ":" << endl;
    cout << coeff*d << ' ' << (b == 0? 0 : -coeff*b) << endl;
    cout << (c == 0? 0 : -coeff*c) << ' ' << coeff*a << endl;
  }
  
  return 0;
}
