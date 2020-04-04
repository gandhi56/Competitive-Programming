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


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n, m;
  cin >> n >> m;

  if (m%n){
    cout << -1 << endl;
    return 0;
  }

  int cnt = 0;
  int d = m/n;
  while (d%2 == 0){
    d >>= 1;
    cnt++;
  }

  while (d%3 == 0){
    d /= 3;
    cnt++;
  }

  cout << (d==1?cnt:-1) << endl;

  return 0;
}
