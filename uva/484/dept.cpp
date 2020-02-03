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
  int x;

  unordered_map<int,int> m;
  vector<int> v;
  while (cin >> x){
    v.pb(x);
    m[x]++;
  }
  set<int> done;
  for (auto x : v){
    if (done.find(x) != done.end()) continue;
    cout << x << ' ' << m[x] << endl;
    done.insert(x);
  }
  return 0;
}
