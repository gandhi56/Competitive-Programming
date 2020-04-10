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

const ull maxn = 1000000000000ULL;
const ull maxnn = 1000001ULL;
ull dp[maxnn];

ull solve(ull x){
  if (x > maxnn or dp[x] != -1)  return dp[x];
  if (x == 0)   return dp[x] =0; 
  ull y = x;
  ull d = 0;
  while (y){
    d = max(d, y%10);
    y /= 10;
  }

  return dp[x] = 1 + solve(x-d);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  memset(dp, -1, sizeof(dp));

  ull x;
  cin >> x;
  cout << solve(x) << endl;

  return 0;
}



