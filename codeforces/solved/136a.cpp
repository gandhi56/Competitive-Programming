#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  map<int,int> m;
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i){
    int x;
    cin >> x;
    m[x] = i;
  }
  for (auto it : m) cout << it.second << ' ';
  cout << endl;
  return 0;
}
