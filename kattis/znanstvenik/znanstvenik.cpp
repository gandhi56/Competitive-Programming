#include <bits/stdc++.h>
using namespace std;

int compute_lcp(string a, string b){
  int i = 0;
  while (a[i] == b[i])  i++;
  return i;
}

int main(){
  int r, c;
  cin >> r >> c;

  vector<string> m;
  for (int i = 0; i < r; ++i){
    string s;
    cin >> s;
    m.push_back(s);
  }

  vector<string> mm(c);
  for (int i = 0; i < c; ++i){
    for (int j = r - 1; j >= 0; --j){
      mm[i] += m[j][i];
    }
  }

  // for (auto& s : mm)  cout << s << endl;

  int lcp = 0;
  for (int i = 0; i < mm.size(); ++i){
    for (int j = i+1; j < mm.size(); ++j){
      lcp = max(lcp, compute_lcp(mm[i], mm[j]));
    }
  }

  cout << r - lcp - 1 << endl;

  return 0;
}