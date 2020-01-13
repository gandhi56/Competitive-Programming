#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  cout << (m >= n and k >= n? "yes":"no") << endl;
  return 0;
}
