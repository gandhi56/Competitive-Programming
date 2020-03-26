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

bool bent(char c){
  return c >= '3' and c <= '6';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int q;
  cin >> q;
  while (q--){
    int n;
    cin >> n;
    
    string g[2];
    cin >> g[0];
    cin >> g[1];
    pii curr = {0,0};
    while (curr.second < n){
      if (g[curr.first][curr.second] >= '3'){
        if (g[curr.first^1][curr.second] < '3')
          break;
        curr.first ^= 1;
      }
      curr.second++;
    }
    if (curr.second == n and curr.first == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  
  return 0;
}
