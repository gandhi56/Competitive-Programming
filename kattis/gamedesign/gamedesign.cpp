#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int main(){

  string s;
  cin >> s;

  set<ii> blk;

  ii pos = {0,0};
  for (char c : s){
    cout << c << endl;
    if (c == 'D'){
      pos.second--;
      if (blk.find({pos.first, pos.second-1}) != blk.end()){
        cout << "impossible " << pos.first << ' ' << pos.second-1 << endl;
        //return 0;
      }
      blk.insert({pos.first, pos.second-1});
    }
    else if (c == 'U'){
      pos.second++;
      if (blk.find({pos.first, pos.second+1}) != blk.end()){
        cout << "impossible " << pos.first << ' ' << pos.second+1 << endl;
        //return 0;
      }
      blk.insert({pos.first, pos.second+1});
    }
    else if (c == 'L'){
      pos.first--;
      if (blk.find({pos.first-1, pos.second}) != blk.end()){
        cout << "impossible " << pos.first-1 << ' ' << pos.second << endl;
        //return 0;
      }
      blk.insert({pos.first-1, pos.second});
    }
    else if (c == 'R'){
      pos.first++;
      if (blk.find({pos.first+1, pos.second}) != blk.end()){
        cout << "impossible " << pos.first+1 << ' ' << pos.second << endl;
        //return 0;
      }
      blk.insert({pos.first+1, pos.second});
    }
  }
  
  cout << "0 0" << endl; 
  cout << blk.size() << endl;
  for (auto it = blk.begin(); it != blk.end(); ++it){
    cout << it->first << ' ' << it->second << endl;
  }
  return 0;
}
