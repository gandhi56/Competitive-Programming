#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int x;
  cin >> x;
  int cnt = 0;
  for (int y = 5; y >= 1; --y){
    cnt += x/y;
    x %= y;
  }
  cout << cnt << endl;
  return 0;
}
