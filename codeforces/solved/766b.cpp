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

bool ok(int a, int b, int c){
  return a+b>c and a+c>b and b+c>a;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n;
  cin >> n;

  vi a(n);
  for (int i = 0; i < n; ++i)   cin >> a[i];

  sort(all(a));

  for (int i = 0; i+2 < n; ++i){
    if (ok(a[i], a[i+1], a[i+2])){
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
  return 0;
}
