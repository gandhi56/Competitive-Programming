#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool isprime(int x){
  for (int d = 2; d*d <= x; ++d)
    if (x%d == 0) return false;
  return true;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;

  for (int x = 4; x < n; ++x){
    if (!isprime(x) and !isprime(n-x)){
      cout << x << ' ' << n-x << endl;
      return 0;
    }
  }

  return 0;
}
