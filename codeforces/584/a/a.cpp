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


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n, t;
  cin >> n >> t;
  
  if (t == 10){
    if (n >= 2){
      for (int i = 0; i < n-1; ++i)
        cout << 1;
      cout << 0 << endl;
    }
    else{
      cout << -1 << endl;
    }
  }
  else{
    for (int i =0 ; i < n; ++i) cout << t;
    cout << endl;
  }

  return 0;
}
