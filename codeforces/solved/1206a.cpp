#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n;

  set<int> a;
  set<int> b;
  while (n--){
    int x;
    cin >> x;
    a.insert(x);
  }

  cin >> m;
  while (m--){
    int x;
    cin >> x;
    b.insert(x);
  }

  for (auto x : a){
    for (auto y : b){
      if (a.find(x+y) == a.end() and b.find(x+y) == b.end()){
        cout << x << ' ' << y << endl;
        return 0;
      }
    }
  }

  return 0;
}
