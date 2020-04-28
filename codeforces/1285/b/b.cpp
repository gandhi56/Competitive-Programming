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

void solve(){
  int n;
  cin >> n;

  vector<ll> a(n);
  for (auto& x : a) cin >> x;

  ll tot = 0;
  for (auto x : a)  tot += x;

  ll sub = tot;
  int i;
  for (i =0 ; i < n; ++i){
    if (a[i] <= 0){
      sub -= a[i];
    }
    else{
      break;
    }
  }

  int j;
  for (j =n-1 ; j >= 0; ++j){
    if (a[j] <= 0){
      sub -= a[j];
    }
    else{
      break;
    }
  }

  if (i == 0 and j == n-1){
    cout << "YES" << endl;
  }
  if (tot > sub){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
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
