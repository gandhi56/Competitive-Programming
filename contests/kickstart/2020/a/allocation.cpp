#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#define pb(x) push_back(x)
#define sz(x) (int)(x).size()
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vii;
typedef vector<vector<ii>> viii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt){

    int n, b;
    cin >> n >> b;

    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a, a+n);
    int cnt =0 ;
    for (int i = 0; i < n; ++i){
      if (b - a[i] >= 0){
        cnt++;
        b -= a[i];
      }
      else{
        break;
      }
    }
    cout << "Case #" << tt << ": " << cnt << endl;

  }
  
  return 0;
}
