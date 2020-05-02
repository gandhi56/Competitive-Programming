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
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll gcd(ll a, ll b, ll& x, ll& y){
  x = 1, y = 0;
  ll x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1){
    ll q = a1 / b1;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a1, b1) = make_tuple(b1, a1 - q * b1);
  }
  return a1;
}


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  ll v, x, m;
  cin >> v >> x >> m;

  // find inv(v)
  ll inv_v;
  ll tmp;
  ll p,q ;

  //gcd(v, m, inv_v, tmp);
  ll ansp = INF;
  ll ansq = INF;
  for (q = 0; q < m; ++q){
    p = (v*q) % m;
    if (q*x <= p and p < q*(x+1)){
      if (p < ansp){
        ansp = p;
        ansq = q;
      }
    }
  }
  if (ansp == INF){
    cout << -1 << endl;
  }
  else{
    cout << ansp << ' ' << ansq << endl;
  }

  return 0;
}
