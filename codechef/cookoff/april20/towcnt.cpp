#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 2001;

int h, n;
int t[maxn];
int x[maxn];
int a[maxn];

void count(int i){
  // towards right
  int cnt = 0;
  int len = 1;
  double prevAng = 0.0;
  double currAng = 0.0; // TODO
  while (i+len < n){
    currAng = calcAngle(i, i+len);
    if (prevAng < currAng){
      
    }
  }
}

void solve(){
  cin >> h >> n;

  for (int i = 0; i < n; ++i)
    cin >> t[i] >> x[i] >> a[i];
  
  for (int i = 0; i < n; ++i){
    count(i);
  }

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}
