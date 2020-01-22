#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int dig(int x, int i){
  return (x/(int)pow(10, i))%10;
}

int cnt_digs(int x){
  int i = 10;
  int cnt = 1;
  while (x/i){
    i *= 10;
    cnt++;
  }
  return cnt;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int l, r;
  cin >> l >> r;
  for (int x = l; x <= r; ++x){
    int n = cnt_digs(x);
    bool ok = true;
    for (int i = 0; i < n and ok; ++i){
      for (int j = i+1; j < n and ok; ++j){
        if (dig(x, i) == dig(x, j)) ok = false;
      }
    }
    if (ok){
      cout << x << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  
  return 0;
}
