#include <bits/stdc++.h>

using namespace std;

int main(){
  int x;
  string s;

  bool v[11];
  memset(v, true, 11);

  while (cin >> x and x){
    cin >> s >> s;
    if (s == "high"){
      for (int i = x; i < 11; ++i)
        v[i] = false;
    }
    else if (s == "low"){
      for (int i = 0; i <= x; ++i)
        v[i] = false;
    }
    else{
      if (v[x])
        cout << "Stan may be honest" << endl;
      else
       cout << "Stan is dishonest" << endl;

      memset(v, true, 11);
    }

  }
  return 0;
}