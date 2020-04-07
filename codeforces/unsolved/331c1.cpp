#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define max(a, b, c) max(a, max(b, c))
#define min(a, b, c) min(a, min(b, c))
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n;
vector<ll> dp(1000000, INF);

ll count(int x){
  if (dp[x] != INF) return dp[x];

  map<int, int> m;
  while (n){
    m[n%10]++;
    n /= 10;
  }

  ll cnt = 0;
  while (x){
    int d;
    for (d = 9; d >= 1 and m[d] == 0; --d){}
    m[d]--;
    m[(x/10)%10]--;
    x -= d;
    m[x%10]++;
    m[(x/10)%10]++;
    cnt++;
    //cout << x << endl;
  }

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  cin >> n;

  cout << cnt << endl;

  return 0;
}
