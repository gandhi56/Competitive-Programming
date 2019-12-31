#define MOD 1000000007
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  string s;
  cin >> s;

  ll res = 0;
  ll k = 1;
  for (int i = s.length() - 1; i >= 0; --i){
    res = (res + (s[i] - '0') * k * (i+1)) % MOD;
    k = (k*10 + 1) % MOD;
  }
  
  cout << res << endl;

  return 0;
}