#include <iostream>
using namespace std;
int main(){
  int h[26];
  for (int i = 0; i < 26; ++i)  cin >> h[i];
  string s;
  cin >> s;

  int hh = 0;
  for (auto c : s){
    hh = max(hh, h[c - 'a']);
  }

  cout << s.length() * hh << endl;

  return 0;
}
