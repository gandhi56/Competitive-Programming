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
  
  int n, p, k;
  cin >> n >> p >> k;

  int t[n];
  for (int i = 0; i < n; ++i)   cin >> t[i];

  double cf = t[0];
  for (int i = 1; i < n; ++i){
    cf += (t[i] - t[i-1]) * (1.0 + 0.01*i*p);
  }
  cf += (k - t[n-1]) * (1.0 + 0.01*n*p);

  cout << fixed << setprecision(8);
  cout << cf << endl;
  
  return 0;
}
