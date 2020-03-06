#define INF 0x3f3f3f3f
#define pb(x) push_back(x)
#define sz(x) (int)(x).size()
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vii;
typedef vector<vector<ii>> viii;

int count(int n, int m, int x){
  int cnt = 0;
  for (int i = 1; i <= n; ++i){
    if (x - i >= 1 and x - i <= m)
      cnt++;
  }
  return cnt;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n, m;
  cin >> n >> m;

  int best = 0;
  for (int tot = 2; tot <= n+m; ++tot){
    best = max(best, count(n, m, tot));
  }

  for (int tot = 2; tot <= n+m; ++tot){
    if (count(n, m, tot) == best){
      cout << tot << endl;
    }
  }


  return 0;
}
