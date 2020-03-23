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

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;

  while (t--){

    int n;
    cin >> n;

    string s;
    cin >> s;

    int x = 0, y = 0;
    for (int i =0; i < n; ++i){
      if (s[i] == 'L' and (i == 0 or (s[i-1] != 'L' and s[i-1] != 'R')))  x--;
      if (s[i] == 'R' and (i == 0 or (s[i-1] != 'L' and s[i-1] != 'R')))  x++;
      if (s[i] == 'U' and (i == 0 or (s[i-1] != 'U' and s[i-1] != 'D')))  y++;
      if (s[i] == 'D' and (i == 0 or (s[i-1] != 'U' and s[i-1] != 'D')))  y--;
    }
    cout << x << ' ' << y << endl;

  }
  
  return 0;
}
