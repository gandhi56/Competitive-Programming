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

int h;
int x[1000010];
ll dist(int p){
  ll d = 0;
  for (int i = 0; i < h; ++i){
    d += min(abs(x[i]), abs(p - x[i]));
  }
  return d;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> h;
  for (int i = 0; i < h; ++i) cin >> x[i];
  sort(x, x+h);
  ll ans = INF;
  
  

  return 0;
}
