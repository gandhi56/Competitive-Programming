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
#define sq(x) (int)(x*x)
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while (t--){
    ll a, b, c, d;
    char op;
    ll num, den;
    cin >> a >> b >> op >> c >> d;
    if (op == '+'){
      num = a*d + b*c;
      den = b*d;
    }
    else if (op == '-'){
      num = a*d - b*c;
      den = b*d;
    }
    else if (op == '*'){
      num = a*c;
      den = b*d;
    }
    else{
      num = a*d;
      den = b*c;
    }
    ll N = num/__gcd(num, den);
    ll D = den/__gcd(num, den);
    if (N > 0 and D < 0){
      N = -N;
      D = -D;
    }
    cout << N << " / " << D << endl;
  }

  return 0;
}
