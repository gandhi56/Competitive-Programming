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
  
  cout << fixed << setprecision(6);

  int n;
  cin >> n;
  while (n--){
    int b;
    double p;
    cin >> b >> p;
    
    double bpm = 60*b/p;
    double minval = 60*(b-1)/p;
    double maxval = 60*(b+1)/p;
    cout << minval << ' ' << bpm << ' ' << maxval << endl;
  }
  
  return 0;
}
