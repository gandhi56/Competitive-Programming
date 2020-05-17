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

pii dig(ull n){
  ull a = 9;
  ull b = 0;
  while (n){
    a = min(a, n%10);
    b = max(b, n%10);
    n /= 10;
  }
  return {a, b};
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;

  while (t--){
    ull x, k;
    cin >> x >> k;
    
    ull cnt = 1;
    while (cnt < k){
      auto p = dig(x);  
      x = x + p.first*p.second;
      if (p.first == 0 or p.second == 0)    break;
      cnt++;
    }

    cout <<x << endl;

  }

  return 0;
}


