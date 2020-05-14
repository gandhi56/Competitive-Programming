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

struct cmp{
  bool operator()(const pii& a, const pii& b) const {
    int len1 = a.second - a.first + 1;
    int len2 = b.second - b.first + 1;
    if (len1 == len2)   return a.first < b.first;
    return len1 > len2;
  }
};

void solve(){
  int n;
  cin >> n;

  vi a(n, 0);

  set<pii, cmp> segs;
  int i = 1;
  segs.insert({0, n-1});
  while (i <= n){
    auto curr = *segs.begin();
    segs.erase(segs.begin());
    int idx = (curr.first + curr.second)/2;
    a[idx] = i;
    if (curr.first < idx){
      segs.insert({curr.first, idx-1});
    }
    if (curr.second > idx){
      segs.insert({idx+1, curr.second});
    }
    i++;
  }
  for (auto x : a)  cout << x << ' ';
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}
