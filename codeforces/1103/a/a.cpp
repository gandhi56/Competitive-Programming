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
  
  string s;
  cin >> s;

  int grid[4][4];
  bool v = false;
  bool h = false;
  for (char c : s){
    if (c == '0'){
      if (v)
        cout << "3 4" << endl;
      else
        cout << "1 4" << endl;
      v = !v;
    }
    else{
      if (h)
        cout << "4 3" << endl;
      else
        cout << "4 1" << endl;
      h = !h;
    }
  }

  return 0;
}
