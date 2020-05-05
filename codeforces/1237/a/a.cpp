#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;

  int fl = 1;
  for (int i = 0; i < n; ++i){
    int x;
    cin >> x;
    if (x % 2 == 0){
      cout << x/2 << endl;
    }
    else{
      cout << (x+fl)/2 << endl;
      fl *= -1;
    }
  }
}
