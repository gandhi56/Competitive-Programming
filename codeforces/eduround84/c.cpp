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
  
  int n, m, k;
  cin >> n >> m >> k;

  for (int i =0 ; i < k; ++i){
    int x, y;
    cin >> x >> y;
  }
  for (int i =0; i < k; ++i){
    int x, y;
    cin >> x >> y;
  }


  cout << 2*(n-1) + (n+1) * (m-1) << endl;
  for (int i =0 ; i < n-1; ++i) cout << 'U';
  for (int i =0 ; i < m-1; ++i) cout << 'L';
  for (int i = 0; i < n; ++i){
    if (i != 0)
      cout << 'D';
    if (i&1)
      for (k = 0; k < m-1; ++k)
        cout << 'L';
    else
      for (k = 0; k < m-1; ++k)
        cout << 'R';
  }
  
  return 0;
}
