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
  ii a[n];
  for (int i = 0; i < n; ++i){
    int x;
    cin >> x;
    a[i] = {x, i+1};
  }
  sort(a, a+n);
  for (int i = 0; i < n/2; ++i){
    cout << a[i].second << ' ' << a[n-i-1].second << endl;
  }
  return 0;
}
