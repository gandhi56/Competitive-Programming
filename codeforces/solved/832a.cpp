#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n, k;
  cin >> n >> k;
  cout <<  ((n/k)&1 ? "YES" : "NO") << endl;
  return 0;
}
