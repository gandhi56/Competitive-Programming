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


void solve(int tc){
  string s;
  cin >> s;

  string ans;
  int a, b;
  a = s[0] - '0';
  for (int k = 0; k < a; ++k)   ans.push_back('(');
  ans.push_back(s[0]);
  for (int i = 1; i < sz(s); ++i){
    a = s[i-1] - '0';
    b = s[i] - '0';
    if (a == b){
      ans.push_back(s[i]);
    }
    else if (a < b){
      for (int k = 0; k < b-a; ++k)   ans.push_back('(');
      ans.push_back(s[i]);
    }
    else{
      for (int k = 0; k < a-b; ++k)   ans.push_back(')');
      ans.push_back(s[i]);
    }
  }
  for (int k = 0; k < (s.back()-'0'); ++k)   ans.push_back(')');

  cout << "Case #" << tc << ": " << ans << endl;

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; ++tc)
    solve(tc);

  return 0;
}
