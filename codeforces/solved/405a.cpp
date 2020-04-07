#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define max(a, b, c) max(a, max(b, c))
#define min(a, b, c) min(a, min(b, c))
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
  
  int n;
  cin >> n;

  vi a(n);
  for (auto& x : a) cin >> x;

  for (int i = n-1; i >= 0; --i){
  
    for (int j = i-1; j >= 0; --j){
      if (a[j] > a[i]){
        swap(a[j], a[i]);
      }
    }

  }

  for (auto x : a)  cout << x << ' ';
  cout << endl;

  return 0;
}
