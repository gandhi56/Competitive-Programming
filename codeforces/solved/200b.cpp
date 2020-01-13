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

  double p[n];
  double a = 0.0;
  for (int i = 0; i < n; ++i){
    cin >> p[i];
    p[i] /= 100.0;
    a += p[i];
  }

  cout << fixed << setprecision(9);
  cout << (a*100.0/n) << endl;

  return 0;
}
