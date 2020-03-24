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

string s;
vector<pair<string, int>> sa;
vi lcp;

void show_lcp(){
  for (auto x : lcp)
    cout << x << endl;
}

void construct_lcp(int n){
  lcp.resize(n);
  lcp[0] = 0;
  for (int i = 1; i < n; ++i){
    int k = 0;
    while (sa[i].first[k] == sa[i-1].first[k])    k++;
    lcp[i] = k;
  }

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;

  while (t--){
    cin >> s;
    sa.clear();
    lcp.clear();

    // construct suffix array
    for (int i = 0; i < sz(s); ++i){
      sa.push_back({s.substr(i, sz(s) - i), i});
    }

    sort(sa.begin(), sa.end());
    construct_lcp(sz(s));
    
    cout << "lcp[] ";
    for (auto x : lcp)   cout << x << ' ';
    cout << endl;

    int tot =0;
    for (int i = 1; i < sz(s); ++i)
      tot += lcp[i];

    int n = sz(s);
    cout << "n = " << n << endl;
    cout << tot << endl;
  
  }
  
  return 0;
}
