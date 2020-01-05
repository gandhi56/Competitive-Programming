#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;

  vector<unsigned int> tk(n);

  int idx = 0;
  while (n--){
    string s;
    cin >> s;
    tk[idx] = 0;
    for (char c : s){
      tk[idx] |= (1<<(c - '0'));
    }
    //cout << tk[idx] << endl;
    idx++;
  }

  int cnt = 0;
  for (int i = 0; i < tk.size(); ++i){
    for (int j = i+1; j < tk.size(); ++j){
      if ((unsigned int)(tk[i]|tk[j]) == 1023){
        cnt++;
        //cout << i << ' ' << j << endl;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
