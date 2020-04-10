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

bool cmp(pii i, pii j){
  return i.second < j.second;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n;
  cin >> n;

  vector<int> a(n);

  for (int i = 0; i < n; ++i){
    int x;
    cin >> x;
    a[i] = x;
  }

  vi res;
  int ans = 0;
  for (int i = 0; i < n; ++i){
    int pos = -1;
    for (int j = 0; j < n; ++j)
      if (pos == -1 or a[j] > a[pos])
        pos = j;
    res.push_back(pos+1);
    ans += i*a[pos] + 1;
    a[pos] = 0;
  }

  cout << ans << endl;
  for (auto x : res)
    cout << x << ' ';
  cout << endl;

  return 0;
}
