#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;

  int idt = 0;
  bool first = false;
  for (int i = 0; i < s.length()-1; ++i){
    if (s[i] == '{'){
      for (int i = 0; i < idt; ++i) cout << ' ';
      cout << s[i] << endl;
      idt += 2;
      //for (int i = 0; i < idt; ++i) cout << ' ';
      first = true;
    }
    else if (s[i] == '}'){
      first = false;
      idt -= 2;
      if (s[i-1] != '{')
        cout << endl;
      for (int i = 0; i < idt; ++i) cout << ' ';
      cout << s[i];
    }
    else if (s[i] == ','){
      cout << s[i] << endl;
      first = true;
    }
    else{
      if (first){
        first = false;
        for (int i = 0; i < idt; ++i) cout << ' ';
      }
      cout << s[i];
    }
  }

  if (s[s.length()-2] != '{') cout << endl;
  cout << '}' << endl;
  return 0;
}
