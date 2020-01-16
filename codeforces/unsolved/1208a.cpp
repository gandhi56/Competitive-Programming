#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

#define MAXN 1000000001

int a, b, n;
int solve(int i){
  if (i == 0) return a;
  if (i == 1) return b;
  return solve((i-1)%3)^solve((i-2)%3);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--){
    cin >> a >> b >> n;
    cout << solve(n) << endl;
  }

  return 0;
}
