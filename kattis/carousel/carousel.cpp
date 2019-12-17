#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> ii;
int main(){

  auto cmp = [](ii a, ii b){
    if (a.first/a.second == b.first/b.second)
      return a.first < b.first;
    return a.first/a.second < b.first/b.second;
  };

  int n, m;
  while (cin >> n >> m){
    // m = max #tickets carl will buy
    if (n == 0 and m == 0)  break;
    priority_queue<ii, vector<ii>, decltype(cmp)> deals(cmp);
    for (int i = 0; i < n; ++i){
      double a, b;
      cin >> a >> b;
      if (a > m)  continue;
      deals.push({a, b});
    }
    if (deals.size() == 0){
      cout << "No suitable tickets offered" << endl;
      continue;
    }
    cout << "Buy " << deals.top().first << " tickets for $" << deals.top().second << endl;
  }
  return 0;
}
