#include <bits/stdc++.h>
using namespace std;

int n;
char g[110][110];
void show_grid(){
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j){
      cout << g[i][j];
    }
    cout << endl;
  }
}

int main(){
  int t;
  cin >> t;
  while (t--){
    cin >> n;
    for (int i = 0; i < n; ++i){
      string s;
      cin >> s;
      for (int j = 0; j < n; ++j)
        g[i][j] = s[j];
    }

    for (int i = 0; i < n; ++i){
      sort(g[i], g[i]+n);
    }

    bool ok = true;
    for (int j = 0; j < n; ++j){
      for (int i = 0; i < n-1 and ok; ++i){
        if (g[i][j] > g[i+1][j])  ok = false;
      }
      if (!ok)  break;
    }

    cout << (ok?"YES":"NO") << endl;

  }
  return 0;
}
