#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n, h;
  cin >> n >> h;

  int a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];

  int w = n;
  for (int i = 0; i < n; ++i){
    if (a[i] > h) w++;
  }
  cout << w << endl;

  return 0;
}
