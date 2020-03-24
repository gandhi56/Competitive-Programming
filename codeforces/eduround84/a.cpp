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

bool solve(int n, int k){
  if (k == 1 and n%2)   return true;
  if (k%2 != n%2)       return false;
  if (k > n/2)          return false;
  return true;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while (t--){

    int n, k;
    cin >> n >> k;

    cout << (solve(n, k)? "YES" : "NO") << endl;

  }
  
  return 0;
}
