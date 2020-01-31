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
  int n, m;
  cin>> n >> m;
  
  string a, b, rem;
  cin >> rem >> b;

  for (int i = 0; i < b.size()-n; ++i)  a += "%";
  a += rem;

  for (int i = m-1; i >= n-1 and i-n>=0 and i>= 0; --i){
    a[i-n] = 'a' + (26 + b[i] - a[i]) % 26;
  }

  cout << a << endl;
  
  return 0;
}
