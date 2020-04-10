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


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int q;
  cin>> q;
  while (q--){
    int n;
    cin >> n;

    vi p;
    for (int i =0 ; i < n; ++i){
      int x;
      cin >> x;
      p.push_back(--x);
    }

    vi cnt(n, 0);
    for (int i = 0; i < n; ++i){
      if (cnt[i])   continue;
      int c = 1;
      int j = p[i];
      while (j != i){
        j = p[j];
        c++;
      }
      j = p[i];
      while (j != i){
        cnt[j] = c;
        j = p[j];
      }
      cnt[j] = c;
    }

    for (auto x : cnt)  cout << x << ' ';
    cout << endl;

  }

  return 0;
}
