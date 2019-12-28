#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

bool comp(ii a, ii b){
  return a.first > b.first;
}

int main(){
  int n;
  cin >> n;

  vector<ii> scores;
  int rk = 1;
  while (n--){
    int x;
    cin >> x;
    if (scores.size() and scores.back().first == x) continue;
    scores.push_back({x, rk++});
  }

  int m;
  cin >> m;
  while (m--){
    int x;
    cin >> x;

    auto it = lower_bound(scores.begin(), scores.end(), make_pair(x, -1), comp);
    cout << (it == scores.end()? scores.size()+1 : it->second) << endl;

  }

  return 0;
}