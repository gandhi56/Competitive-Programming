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
  
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> b(n);

    for (auto& x : a)   cin >> x;
    for (auto& x : b)   cin >> x;

    if (a[0] != b[0]){
      cout << "NO" << endl;
      continue;
    }
    
    int pos = 0, neg =0 ;

    // find the leftmost 1 and -1
    int z1 = -1, z2 = -1;
    for (int i = 0; i < n; ++i){
      if (a[i] == 1 and z1 == -1){
        z1 = i;
      }
      if (a[i] == -1 and z2 == -1){
        z2 = i;
      }
      if (b[i] - a[i] > 0)  pos++;
      if (b[i] - a[i] < 0)  neg++;
    }

    if ((pos > 0 and z1 == -1) or (neg > 0 and z2 == -1)){
      cout << "NO" << endl;
      goto L;
    }

    for (int i = 0; i <= z1; ++i){
      if (b[i] - a[i] > 0){
        cout << "NO" << endl;
        goto L;
      }
    }
    
    for (int i = 0; i <= z2; ++i){
      if (b[i] - a[i] < 0){
        cout << "NO" << endl;
        goto L;
      }
    }

    cout << "YES" << endl;
L:;

  }

  return 0;
}
