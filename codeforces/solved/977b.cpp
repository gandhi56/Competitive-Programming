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

int count(string s, string t){
  int cnt = 0;
  for (int i = 0; i+sz(t)-1 < sz(s); ++i){
    string sub = s.substr(i, sz(t));
    if (sub == t) cnt++;
  }
  return cnt;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;

  string ans;
  int maxCnt = -1;
  int cnt;
  for (int i = 0; i+1< n; ++i){
    if ((cnt = count(s, s.substr(i, 2))) > maxCnt){
      maxCnt = cnt;
      ans = s.substr(i, 2);
    }
  }

  cout << ans << endl;

  return 0;
}
