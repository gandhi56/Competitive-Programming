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
  int n;
  cin >> n;

  int p = n-1;
  for (int i = 0; i < 2*n+1; ++i){
    if (i == 0 or i == 2*n){
      int j = abs(n-i);
      while (j--){
        cout << "  ";
      }
      cout << 0 << endl;
    }
    else if (i <= n){
      // i is the max number in this row
      int j = n-i;
      while (j--){
        cout << "  ";
      }
      for (j = 0; j <= i; ++j){
        cout << j << ' ';
      }
      for (j = i-1; j > 0; --j){
        cout << j << ' ';
      }
      if (i)
        cout << 0 << endl;
      else
        cout << endl;
      
    }
    else{
      int j = i-n;
      while (j--){
        cout << "  ";
      }
      for (j = 0; j <= p; ++j){
        cout << j << ' ';
      }
      for (j = p-1; j > 0; --j){
        cout << j << ' ';
      }
      if (i)
        cout << 0 << endl;
      else
        cout << endl;
      p--;
    }
  }

  return 0;
}
