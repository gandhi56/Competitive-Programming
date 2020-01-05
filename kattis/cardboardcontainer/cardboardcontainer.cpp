#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

inline int sa(int l, int w, int h){
  return 2*(l*w + w*h + l*h);
}

int main(){
  int v;
  cin >> v;

  if (v == 1){
    cout << 6 << endl;
    return 0;
  }

  int ans = INF;
  for (int l = 1; l*l <= v; ++l){
    for (int w = 1; w*w <= v; ++w){
      if (v % (l*w))  continue;
      int h = v / (l*w);
      ans = min(ans, sa(l, w, h));
    }
  }

  cout << ans << endl;

  return 0;
}
