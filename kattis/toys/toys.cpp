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
#define MAXN 10000001

int survive[MAXN];

void josephus(int n, int m){
  int i;
  survive[i] = 0;
  for (i = 2; i <= n; ++i){
    survive[i] = (survive[i-1] + (m%i)) % i;
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n, m;
  cin >> n >> m;
  josephus(n, m);
  cout << survive[n] << endl;
  
  return 0;
}
