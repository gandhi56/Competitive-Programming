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

int n
vi t;
vi c;

int getcol(int u){
  if (u == 0) return 1;
  if (u == 1) return 0;
}

int mincol(vi& t, int n){
  if ((n&1) == 0){
    int k = 1;
    for (int i = 0; i < n; ++i)
      if (t[i] != t[(i+1)%n])
        k = 2;
    return k;
  }

  for (int i = 0; i < n; ++i){
    if (t[i] != t[(i+1)%n] and t[(i+1)%n] != t[(i+2)%n] and t[(i+2)%n] != t[i])
      return 3;
    if (t[i] != t[(i+1)%n])
      return 2;
    if (t[(i+1)%n] != t[(i+2)%n])
      return 2;
    if (t[i] != t[(i+2)%n])
      return 2;
  }
  return 1;
}

void solve(){
  c[0] = 1;
  for (int i = 1; i < n; ++i){
    if (c[i] != -1) continue;
    if (t[i] == t[i-1]){
      c[i] = c[i-1];
    }
    else{
      // ti != ti-1
      int k = 1;
      if (c[i-1] == 1)  k = 2;
      if (t[i] == t[(i+1)%n]){
        c[i] = k;
        c[(i+1)%n] = k;
      }
      else{
        c[i] = k;
      }
    }
  }


  for (auto x : c)  cout << x << ' ';
  cout << endl;

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int q;
  cin >> q;
  while (q--){
    cin >> n;

    t.resize(0);
    t.resize(n);
    for (auto& x : t) cin >> x;

    c.resize(0);
    c.assign(n, -1);

  }
  
  return 0;
}










