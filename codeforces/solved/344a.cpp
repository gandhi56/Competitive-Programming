#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s, t;
  cin >> s;
  n--;
  int cnt = 1;
  while (n--){
    cin >> t;
    if (s != t) cnt++;
    s = t;
  }
  cout << cnt << endl;
  return 0;
}
