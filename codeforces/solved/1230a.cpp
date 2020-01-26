#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll a[4];
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  cout << (a[0]+a[3]==a[1]+a[2] or 
            a[0]+a[1]==a[2]+a[3] or 
            a[0]+a[2]==a[1]+a[3] or
            a[3]+a[1]+a[2] == a[0] or
            a[0]+a[3]+a[2] == a[1] or 
            a[0]+a[1]+a[3] == a[2] or 
            a[0]+a[1]+a[2] == a[3]?"YES":"NO") << endl;
  return 0;
}
