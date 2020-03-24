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

vi pi(const string& s){
  vi p(sz(s));
  for(int i = 1; i < sz(s); ++i){
    int g = p[i-1];
    while (g and s[i] != s[g])  g = p[g-1];
    p[i] = g + (s[i] == s[g]);
  }
  return p;
}

vi match(const string& s, const string& pat){
  vi p = pi(pat + '\0' + s), res;
  for (int i = sz(p) - sz(s); i < sz(p); ++i)
    if (p[i] == sz(pat))
      res.push_back(i - 2 * sz(pat));
  return res;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  string p,t;
  while (getline(cin, p)){
    getline(cin, t);
    vi res = match(t, p);
    for (auto x : res)  cout << x << ' ';
    cout << endl;
  }
  
  return 0;
}
