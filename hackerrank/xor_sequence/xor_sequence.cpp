#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll g(ll i){
  ll a = i % 8;
  if (a <= 1) return i;
  if (a <= 3) return 2;
  if (a <= 5) return i+2;
  return 0;
}

int main(){
  unsigned int q;
  cin >> q;
  while (q--){
    ll l, r;
    cin >> l >> r;
    cout << (g(l-1) ^ g(r)) << endl;
  }
  return 0;
}





