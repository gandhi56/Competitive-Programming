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

    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    map<int,int> m;
    for (int i=0; i < n; ++i)
      m[a[i]]++;

    int same = -1;
    int y =0;
    for (auto p : m)
      y = max(y, p.second);

    int x = sz(m)-1;
    //cout << "y = " << y << endl;
    //cout << "x = " << x  << endl;

    if (x >= y){
      cout << y << endl;
    }
    else{
      cout << x + ((y-x)/2)<< endl;
    }
  }

  return 0;
}
