#define LIN cout << __LINE__ << endl;
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

bool in(int a, int b, int c){
  return a <= b and b <= c;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;

  while (t--){
    int n;
    cin >> n;

    int tax = 0;
    if (n > 250000)
      tax += ((min(500000,n) - 250000) * 5)/100;
    if (n > 500000)
      tax += ((min(750000,n) - 500000) * 10)/100;
    if (n > 750000)
      tax += ((min(1000000,n) - 750000) * 15)/100;
    if (n > 1000000)
      tax += ((min(1250000,n) - 1000000) * 20)/100;
    if (n > 1250000)
      tax += ((min(1500000,n) - 1250000) * 25)/100;
    if (n > 1500000)
      tax += ((n - 1500000) * 30)/100;
    cout << n - tax << endl;
  }
  
  return 0;
}
