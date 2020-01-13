#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, c;
  cin>> n >> c;
  int a, b;
  cin >> a;
  int cnt = 1;
  for (int i = 1; i < n; ++i){
    cin >> b;
    if (b-a <= c){
      cnt++;
    }
    else{
      cnt = 1;
    }
    a = b;
  }
  cout << cnt << endl;
  return 0;
}
