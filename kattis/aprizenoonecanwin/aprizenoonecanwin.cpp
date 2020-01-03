#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, x;
  cin >> n >> x;

  int p[n];
  for (int i = 0; i < n; ++i) cin >> p[i];

  sort(p, p+n);
  vector<int> items;
  for (int i = 0; i < n; ++i){
    if (!items.empty() and items.back()+p[i] > x){
      break;
    }
    items.push_back(p[i]);
  }
  cout << items.size() << endl;

  return 0;
}
