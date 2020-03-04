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
  
  string s;
  set<string> ss;
  string ans = "yes";
  while (cin >> s){
    if (ss.find(s) != ss.end()) ans = "no";
    ss.insert(s);
  }
  cout << ans << endl;
  
  return 0;
}
