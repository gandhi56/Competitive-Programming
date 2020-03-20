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
  while (t--){
    int s, i, e;
    cin >> s >> i >> e;
  
    int k = max(0, (e + i - s + 2)/2);
    int cnt = max(0, e - k + 1);
    cout << cnt << endl;
  
  }
  
  return 0;
}
