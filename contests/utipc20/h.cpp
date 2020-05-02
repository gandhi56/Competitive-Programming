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
  
  string board[8];
  for (int i =0 ; i < 8; ++i)
    cin >> board[i];

  int cnt = 0;
  for (int i =0 ; i < 8; ++i){
    for (int j = 0; j < 8; ++j){
      bool rook = false;
      for (int k = 0; k < 8 and !rook; ++k){
        if (board[i][k] == 'R' or board[k][j] == 'R')
          rook = true;
      }
      if (!rook)    cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}
