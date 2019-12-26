#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
  string s;
  cin >> s;

  unordered_map<char, int> cnt;
  for (char c : s){
    if (cnt.find(c) == cnt.end()){
      cnt[c] = 0;
    }
    cnt[c]++;
  }

  unordered_map<int,int> cnt2;
  for (auto it = cnt.begin(); it != cnt.end(); ++it){
    if (cnt2.find(it->second) == cnt2.end()){
      cnt2[it->second] = 0;
    }
    cnt2[it->second]++;
  }

  if (cnt2.size() > 2){
    cout << "NO" << endl;
    return 0;
  }
  else if (cnt2.size() == 1){
    cout << "YES" << endl;
    return 0;
  }
  else{
    auto it = cnt2.begin();
    if (it->second == 1 and (it++)->second){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
  return 0;
}
