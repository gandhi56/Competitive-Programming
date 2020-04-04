#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n;
  cin >> n;

  vi a(n);
  for (auto& x : a) cin >> x;

  sort(begin(a), end(a));

  int tot = 0;
  for (auto x : a)
    tot += x;

  int x = 0;
  int y = tot;

  int cnt = 0;
  for (int i = sz(a)-1; i >= 0; --i){
    x += a[i];
    y -= a[i];
    cnt++;
    if (x > y)
      break;
  }
  cout << cnt << endl;

  return 0;
}
