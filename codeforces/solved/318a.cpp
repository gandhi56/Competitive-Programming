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


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  ll n, k;
  cin >> n >> k;

  ll x = (n&1)? n/2+1 : n/2;

  if (k <= x)
    cout << 2*k-1 << endl;
  else
    cout << 2*(k - x) << endl;

  return 0;
}
