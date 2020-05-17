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

bool ok(int x, int y, int z){
  return x+y>z and x+z>y and y+z>x;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int n = 1000007;
  ll cnt = 0;
  ll pf[1000007];
  for (int i = a; i <= b; ++i){
    pf[i+b]++;
    pf[i+c+1]--;
  }
  for (int i = 1; i < n; ++i)
    pf[i] += pf[i-1];
  for (int i = 1; i < n; ++i)
    pf[i] += pf[i-1];

  for (int i = c; i <= d; ++i)
    cnt += pf[n-1] - pf[i];

  cout << cnt << endl;

  return 0;
}
