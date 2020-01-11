#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;

  int l = 0;
  int r = 0;
  for (auto c : s){
    if (c == 'R') r++;
    if (c == 'L') l++;   
  }

  set<int> cnt;
  for (int k = 0; k <= n; ++k){
    // k R's not working
    int rr = r - k;
    int ll = l - k;
    cnt.insert(l+rr);
    cnt.insert(r+ll);
  }
  cout << cnt.size() << endl;
  
  return 0;
}
