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
#define sq(x) (int)(x*x)
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 300;
ll memo[maxn];
vi den({1, 2, 5, 10, 20, 50, 100, 200});

ll solve(int x){
  // cout << x << endl;
  memo[0] = 1;
  for (auto d : den){
    for (int i = 0; i <= x-d; ++i){
      memo[i+d] += memo[i];
    }
  }
  return memo[x];
}


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  memset(memo, 0, sizeof(memo));
  cout << solve(200) << endl;

  return 0;
}














