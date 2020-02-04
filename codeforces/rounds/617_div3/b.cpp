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
    ll s;
    cin >> s;
  
    ll spent = 10*(s/10);
    ll gain = s/10;
    ll rem = (s - spent + gain);
    ll nxt = 10*(rem/10) + rem/10 + rem%10;
    //cout << "spent = " << spent << endl;
    //cout << "gain = " << gain << endl;
    //cout << "rem = " << rem << endl;
    cout << spent + nxt << endl;
  
  }
  
  return 0;
}
