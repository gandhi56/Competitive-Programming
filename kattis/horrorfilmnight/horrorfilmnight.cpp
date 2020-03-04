#define INF 0x3f3f3f3f
#define pb(x) push_back(x)
#define sz(x) (int)(x).size()
#define LIN cout << __LINE__ << endl;
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vii;
typedef vector<vector<ii>> viii;

const int sz = 1000001;

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
  
  int ans = 0;
  bool x = true;
  bool y = true;
  for (int i = 0; i < sz(pref); ++i){
    if (pref[i] == 'Z'){
      x = y = true;
      ans++;
    }
    else if (pref[i] == 'X' and y){
      x = true;
      y = false;
      ans++;
    }
    else if (pref[i] == 'Y' and x){
      x = false;
      y = true;
      ans++;
    }
  }
  cout << ans << endl;
  
  return 0;
}









