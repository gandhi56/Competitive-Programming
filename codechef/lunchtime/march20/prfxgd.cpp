#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(){
  string s;
  int k, x;
  cin >> s;
  cin >> k >> x;
  
  string p;

  map<char, int> m;
  for (char c : s){
    if (k == 0 and m[c] == x)   break;
    if (m.find(c) == m.end())
      m[c] = 0;
    if (m[c] < x){
      p.push_back(c);
      m[c]++;
    }
    else{
      // delete char
      k--;
    }
  }
  cout << sz(p) << endl;
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
