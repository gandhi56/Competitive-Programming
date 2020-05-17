#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool ok(char a, char b, char c){
  return (a != b and a != c and b != c);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while (t--){
    string s;
    cin >> s;

    int ans = INF;
    int n = sz(s);

    vi idx;
    for (int i = 1; i < n; ++i){
      if (s[i] != s[i-1]){
        idx.push_back(i-1);
      }
    }


    for (int i = 0; i+1 < sz(idx); ++i){
      char a = s[idx[i]];
      char b = s[idx[i]+1];
      char c = s[idx[i+1]+1];
      if (ok(a, b, c)){
        ans = min(ans, idx[i+1]+1 - idx[i]+ 1);
      }
    }

    cout << (ans == INF? 0 : ans) << endl;

  }

  return 0;
}
