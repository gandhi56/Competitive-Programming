#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main(){
  int n;
  cin >> n;
  // poolmap maps from energy quests to a heap of gold rewards
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
      int x, g = 0;
      cin >> x;
      while (x and !poolmap.empty()){
        // if it maps to y st y >= x, then it-- maps to w st w < x 
        // (if they exist)
        auto it = poolmap.lower_bound(x); // finds first y with >= x
        if (it == poolmap.end())  it--; // previous iter must be y < x
        if (it == poolmap.begin() and it->first > x)  break;  // no such y
        if (it->first > x)  it--;
        x -= it->first;
        g += it->second.top();
        it->second.pop();
        if (it->second.empty())  poolmap.erase(it);
      }
      cout << g << endl;
    }
  }
  return 0;
}