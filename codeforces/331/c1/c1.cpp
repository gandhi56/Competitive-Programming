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

ull ldig(ull x){
  ull d = 0;
  while(x){
    d = max(d, x%10);
    x /= 10;
  }
  return d;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  ull n;
  cin >> n;

  int cnt = 0;
  while (n > 0){
    ull d = ldig(n);
    n -= d;
    cnt++;
  }
  cout << cnt << endl;

  return 0;
}
