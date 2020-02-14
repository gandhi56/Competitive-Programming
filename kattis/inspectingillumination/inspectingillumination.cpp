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

#define MAXN 11

vector< bitset<100> > m(100);
int n;

void show(){
  for (int i = 1; i <= n; ++i)
    cout << i << ' ' << m[i] << endl;
}

void query(int lo, int hi){
  int len = hi - lo + 1;
  cout << "ASK " << hi - lo + 1 << ' ';
  for (int i = lo; i <= hi; ++i)
    cout << i << ' ';
  cout << endl;
  vb v(n+1, false);
  while (len--){
    int x;
    cin >> x;
    v[x] = true;
  }

  for (int i = 1; i <= n; ++i){
    for (int j = 1; j <= n; ++j){
      if (!v[j]){
        m[i].set(j, false);
      }
      else{
        m[i].set(j, true);
      }
    }
  }

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  cin >> n;

  for (int i = 1; i < MAXN; ++i){
    if (i > n){
      m[i].reset();
      continue;
    }
    for (int j = 1; j <= n; ++j){
      m[i].set(j, 1);
    }
  }

  query(1, n/2);
  cout << "print answer" << endl;
  show();

  return 0;
}
