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

bool ispal(string s, int n){
  for (int i = 0; i < n/2+1; ++i){
    if (s[i] != s[n-1-i])   return false;
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  string s;
  int t;
  cin >> t;
  while (t--){
    cin >> s;

    int n = sz(s);
  
    vector<string> pref;
    vector<string> suf;
    pref.push_back(s.substr(0, 1));
    for (int i = 1; i < n; ++i){
      pref.push_back(pref.back() + s[i]);
    }

    suf.push_back(s.substr(n-1, 1));
    for (int i = n-2; i >= 0; --i){
      suf.push_back(s[i] + suf.back());
    }
    pref.push_back("");
    suf.push_back("");

    if (n == 1){
      cout << s << endl;
      continue;
    }

    string ans = "";
    int ansLen = 0;
    for (int i =0 ; i < pref.size(); ++i){
      for (int j = 0; j < suf.size(); ++j){
        int n1 = sz(pref[i]);
        int n2 = sz(suf[j]);
        if (ispal(pref[i]+suf[j], n1+n2) and n1+n2 > ansLen and n1+n2 <= n){
          ansLen = n1+n2;
          ans = pref[i] + suf[j];
        }
      }
    }
    cout << ans << endl;
  
  }
  return 0;
}
