#define INF 1e9
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

#define MAXN 100010
#define K 30

int inp[MAXN];
int cnt[MAXN];
int logVal[MAXN+1];
int st[MAXN][K];

inline int rmq(int l, int r){
  int j = logVal[r-l+1];
  return max(st[l][j], st[r - (1<<j)+1][j]);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  logVal[1] = 0;
  for (int i = 2; i <= MAXN; ++i) logVal[i] = logVal[i/2] + 1;

  int n, q;
  while (cin >> n and n){
    cin >> q;
    for (int i = 0; i < n; ++i) cin >> inp[i];

    for (int i = 0; i < n;){
      int j = i;
      for (; j < n and inp[i] == inp[j]; j++){}
      int len = j-i;
      for (int j = i; j < i+len; ++j)
        cnt[j] = len;
      i = j;
    }

    // sparse table
    for (int i = 0; i < n; ++i) st[i][0] = cnt[i];
    for (int j = 1; j <= K; ++j)
      for (int i = 0; i + (1<<j) <= n; ++i)
        st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);

    while (q--){
      int l, r;
      cin >> l >> r;
      l--;
      r--;

      if (l == r){
        cout << 1 << endl;
        continue;
      }
      else if (r-l == 1){
        cout << (cnt[l] == cnt[r]?2 : 1) << endl;
        continue;
      }

      int m = l;
      for (; m <= r and cnt[l] == cnt[m]; ++m){}
      cout << max(m-l+1, rmq(m+1, r)) << endl;
    }

  }

  return 0;
}
