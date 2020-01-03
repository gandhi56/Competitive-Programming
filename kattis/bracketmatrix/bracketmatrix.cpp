#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  char m[n][n];
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j) cin >> m[i][j];
  }

  int s[n];
  memset(s, 0, sizeof(s));

  for (int j = 0; j < n; ++j){
    int open = 0;
    int close = 0;
    for (int i = 0; i < n; ++i){
      if (m[i][j] == '(') ++open;
      else  ++close;
    }
    for (int k = 0; k < open; ++k)  s[k]++;
    for (int k = open; k < n; ++k)  s[k]--;
    sort(s, s+n);
    if (s[0] < 0){
      cout << "No" << endl;
      return 0;
    }
  }

  if (s[n-1] == 0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }

  return 0;
}
