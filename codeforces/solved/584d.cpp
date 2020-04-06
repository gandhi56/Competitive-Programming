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

const int maxn = 1e9;

bool isprime(int x){
  for (int d = 2; d*d <= x; ++d)
    if (x % d == 0)
      return false;
  return true;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  

  int n;
  cin >> n;

  if (isprime(n)){
    cout <<1 << endl << n << endl;
    return 0;
  }
  else if (isprime(n-2)){
    cout << 2 << endl;
    cout << 2 << ' ' << n-2 << endl;
  }
  else{
    for (int i = 3; i < n; i += 2){
      if (isprime(i) and isprime(n-i-3)){
        cout << 3 << endl;
        cout << 3 << ' ' << i << ' ' << n-i-3 << endl;
        return 0;
      }
    }
  }

  return 0;
}
