#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  map<int,int> m;
  for (int i = 1; i <= n; ++i){
    int a;
    cin >> a;
    m[a] = i;
  }

  if (m.size() >= k){
    cout << "YES" << endl;
    int cnt = 0;
    for (auto it : m){
      cout << it.second << ' ';
      cnt++;
      if (cnt == k) break;
    }
    cout  << endl;
    return 0;
  }
  cout << "NO" << endl;

  return 0;
}
