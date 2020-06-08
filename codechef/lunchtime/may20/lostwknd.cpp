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

void solve(){
  int a[5];
  int p;
  for (int i = 0; i < 5; ++i)
    cin >> a[i];
  cin >> p;
  int tot =0;
  for (int i = 0; i < 5; ++i){
    a[i] *= p;
    tot += a[i];
  }
  if (tot > 5*24){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
