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

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;

    int w[n];
    int m;
    for (int i =0; i < n; ++i){
      cin >> w[i];
      m = max(m, w[i]);
    }

    int firstHalf = 0, secHalf = 0;
    for (int i = 0; i < n/2; ++i)
      if (w[i] == m)
        firstHalf++;

    for (int i = n/2; i < n; ++i)
      if (w[i] == m)
        secHalf++;


    if (firstHalf and secHalf)
      cout << 0 << endl;
    else if (firstHalf==0 and secHalf == 0)
      cout << n << endl;
    else
      cout << n/2 << endl;

  }
  
  return 0;
}
