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


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;

  string s;
  cin >> s;

  int open = 0;
  int close = 0;
  for (char c : s)
    if (c == '(')
      open++;
    else
      close++;
  
  if (open != close){
    cout << -1 << endl;
    return 0;
  }

  pii curr = {0,0};
  int ans = 0;
  vi a;
  a.push_back(0);
  for (int i = 0; i < n; ++i){
    if (s[i] == '('){
      curr.first++;
      curr.second++;
    }
    else{
      curr.first++;
      curr.second--;
    }
    a.push_back(curr.second);
  }

  for (int i = 1; i <= n; ++i){
    if (a[i] < 0 or (a[i] == 0 and a[i-1] < 0)){
      // cout << i << endl;
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
