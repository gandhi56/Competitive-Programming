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

void solve(){
  int n;
  cin >> n;

  vii g(n);
  for (int i = 0; i < n; ++i){

    int k;
    cin >> k;

    while (k--){
      int x;
      cin >> x;
      g[i].push_back(--x);
    }
  }

  vi A(n, -1);
  vb matched(n, false);
  for (int i = 0; i < n; ++i){
    for (auto x : g[i])
      if (!matched[x]){
        matched[x] = true;
        A[i] = x;
        break;
      }
  
  }

  int i = 0, j = 0;
  while (i < n and A[i] != -1)  i++;
  while (j < n and matched[j])  j++;
  if (i == n and j == n){
    cout << "OPTIMAL" << endl;
  }
  else{
    cout << "IMPROVE" << endl;
    cout << i+1 << ' ' << j+1 << endl;
  }

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while (t--){
    solve();
  }
  
  return 0;
}
