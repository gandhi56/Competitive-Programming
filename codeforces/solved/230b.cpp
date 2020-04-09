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

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  ull N = 10000000;
  vector<char> isprime(N+1, true);
  isprime[1] = false;
  for (ull d = 2; d <= N; ++d){
    if (isprime[d]){
      for (ull p = d*d; p <= N; p += d)
        isprime[p] = false;
    }
  }

  set<ull> ans;
  for (ull p = 2; p <= N; ++p)
    if (isprime[p])
      ans.insert(p*p);

  int n;
  cin >> n;

  while (n--){
    ull x;
    cin >> x;
    if (ans.find(x) != ans.end()){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }

  return 0;
}
