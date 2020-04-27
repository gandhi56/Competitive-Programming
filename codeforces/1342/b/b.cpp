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


void solve(){
  string t;
  cin >> t;

  int x = 0;  // #0s
  int y = 0;  // #1s
  for (auto c : t){
    if (c == '0')
      x++;
    else
      y++;
  }

  if (x == 0){
    string s;
    while (y--)
      s += "1";
    cout << s << endl;
  }
  else if (y == 0){
    string s;
    while (x--)
      s += "0";
    cout << s << endl;
  }
  else{
    int k = sz(t);
    string s = "10";
    for (int i = 2; i <= k; ++i){
      s += "10";
    }
    cout << s << endl;
  }

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--)
    solve();
  return 0;
}
