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

ll countNonDivs(ll n, ll T){
  return (T/n)*(n-1) + (T % n);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin  >> t;
  while (t--){
    ll n, k;
    cin >> n >> k;

    ll lo = 1;
    ll hi = n*1000000000;
    while (lo < hi){
      ll mid = lo + (hi - lo)/2;
      ll divs = countNonDivs(n, mid);
      if (divs <= k-1){
        lo = mid + 1;
      }
      else{
        hi = mid;
      }
    }

    cout << lo << endl;

  }

  return 0;
}
