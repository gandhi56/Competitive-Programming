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


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n;
  cin >> n;

  int x[n], y[n];
  for (int i  = 0; i < n; ++i)
    cin >> x[i] >> y[i];

  map<int,int> homeCount;
  for (int i = 0; i < n; ++i)
    homeCount[x[i]]++;



  int ans[n];   // number of times team i will use home kit
  // = #games played as home + #games played as away and there is a match
  memset(ans, 0, sizeof(ans));
  for (int i =0 ; i < n; ++i){
    int c = n-1 + homeCount[y[i]];
    cout << c << ' ' << 2*(n-1) - c << endl;
  }

  return 0;
}
