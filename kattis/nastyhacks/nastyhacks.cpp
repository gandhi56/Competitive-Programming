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
  
  int n;
  cin >> n;

  while (n--){
    int r, e, c;
    cin >> r >> e >> c;
    if (r+c == e){
      cout << "does not matter" << endl;
    }
    else if (r+c < e){
      cout << "advertise" << endl;
    }
    else if (r+c > e){
      cout << "do not advertise" << endl;
    }
  }
  
  return 0;
}
