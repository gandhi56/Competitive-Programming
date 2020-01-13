#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a+3);

  int cnt = 0;
  while (a[0] + a[1] <= a[2]){
    cnt++;
    a[0]++;
  }

  while (a[1] + a[2] <= a[0]){
    cnt++;
    a[1]++;
  }

  while (a[2] + a[0] <= a[1]){
    cnt++;
    a[2]++;
  }

  cout << cnt << endl;

  return 0;
}
