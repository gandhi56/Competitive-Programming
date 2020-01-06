#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main(){
  int n;
  cin >> n;
  map<int,priority_queue<int>> poolmap;
  while (n--){
    string s;
    cin >> s;
    if (s == "add"){
      int e, g;
      cin >> e >> g;
      poolmap[e].push(g);
    }
    else{
      long long x, g = 0;
      cin >> x;
      while (!poolmap.empty()){
        auto it = poolmap.upper_bound(x);
        
        // it points to an energy quest y, y > x
        // if it is the begin iterator, quests are too expensive
        // otherwise, the preceding iterator w <= x
        
        if (it == poolmap.begin())  break;
        it--;
        assert(it->first <= x); // this holds!
        x -= it->first; // reduce energy
        g += it->second.top();  // collect gold reward
        it->second.pop(); // clear quest
        if (it->second.empty())  poolmap.erase(it);
        if (x == 0) break;
      }
      cout << g << endl;
    }
  }
  return 0;
}
