#include <bits/stdc++.h>
using namespace std;
int main(){
  int c, n;
  cin >> c >> n;

  int x = 0;
  string ans = "possible";
  while (n--){
    int u, v, w;;
    cin >> u >> v >> w;
    x -= u;
    if (ans == "possible" and x < 0){
      ans = "impossible";
    }

    x += v;
    if (ans == "possible" and x > c){
      ans = "impossible";
    }

    if (ans == "possible" and x < c and w > 0){
      ans = "impossible";
    }

    if (ans == "possible" and n == 0 and w) ans = "impossible";
  }

  if (ans == "possible" and x > 0){
    ans = "impossible";
  }
  cout << ans << endl;

  return 0;
}
