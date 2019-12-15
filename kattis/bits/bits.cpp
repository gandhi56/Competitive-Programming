#include <bits/stdc++.h>
using namespace std;

void solve(int x){
  int ans = 0;
  while (x){
    ans = max(ans, __builtin_popcount(x));
    x /= 10;
  }
  cout << ans << endl;
}

int main(){
  int t;
  cin >> t;
  while (t--){
    int x;
    cin >> x;
    solve(x);
  }
  
  return 0;
}
