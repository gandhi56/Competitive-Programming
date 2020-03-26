#define LIN cout << __LINE__ << endl;
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

bool solve(ll n, ll k){
  if (k*k <= n and (n&1) == (k&1))  return true;
  return false;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while (t--){

    ll n, k;
    cin >> n >> k;

    cout << (solve(n, k)? "YES" : "NO") << endl;

  }
  
  return 0;
}
