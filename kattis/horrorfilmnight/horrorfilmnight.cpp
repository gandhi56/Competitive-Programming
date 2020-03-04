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

const int sz = 10;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
   
  vector<char> pref(sz, ' ');
  int k;
  cin >> k;
  while (k--){
    int d;
    cin >> d;
    pref[d] = 'X';
  }

  cin >> k;
  while (k--){
    int d;
    cin >> d;
    pref[d] = (pref[d] == 'X'? 'Z':'Y');
  }

  int i = 0;
  int ans = 1;
  while (i+1 < sz){
    // cout << i << endl;
    if (pref[i] == 'X' or pref[i] == 'Y'){
      if (pref[i+1] == pref[i]) break;  // can't watch the next movie
      if (pref[i+1] != ' ') ans++;
    }
    else if (pref[i] == 'Z'){
      ans++;
    }
    i++;
  }
  cout << ans << endl;

  return 0;
}









