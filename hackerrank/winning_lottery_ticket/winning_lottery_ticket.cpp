#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;

  unordered_map<string, int> tk;

  while (n--){
    string s;
    cin >> s;
    tk[s] = 0;
    for (auto c : s){
      tk[s] |= (1<<(int)(c - '0'))
      if (tk[s] == 1023)  break;
    }
  }

  int cnt = 0;
  for (auto it1 = tk.begin(); it1 != tk.end(); ++it){
  }

  return 0;
}
