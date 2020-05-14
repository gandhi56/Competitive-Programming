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
  
  int t;
  cin >> t;
  while (t--){

    int n, k;
    cin >> n >> k;

    vi ans;
    if (n - (k-1) > 0 and (n-k+1)%2 == 1){
      cout << "YES" << endl;
      for (int i = 0; i < k-1; ++i)
        cout << "1 ";
      cout << n-(k-1) << endl;
    }
    else if (n-2*(k-1) > 0 and (n-2*k+2)%2 == 0){
      cout << "YES" << endl;
      for (int i = 0; i < k-1; ++i)
        cout << "2 ";
      cout << n-2*k+2 << endl;
    }
    else{
      cout << "NO" << endl;
    }


  }

  return 0;
}
