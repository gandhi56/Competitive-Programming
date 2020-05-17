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

int solve(int r, int a, int b){
  if (a/2 == b/2)
    return r;
  return solve(r+1, a/2, b/2);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n, a, b;
  cin >> n >> a >> b;
  --a; --b;
  int ans = solve(1, a, b);

  if (ans == log2(n))
    cout << "Final!" << endl;
  else
    cout << ans << endl;

  return 0;
}
