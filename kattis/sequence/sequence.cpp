#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;

  vector<int> ans;
  ans.push_back(1);
  while ((ans.back()<<1) <= n){
    ans.push_back(ans.back()<<1);
  }
  cout << ans.size() << endl;
  for (auto& x : ans) cout << x << ' ';
  cout << endl;
  return 0;
}