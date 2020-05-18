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

const int maxn = 1e6+7;
int seg[maxn*3];

void add(int idx, int val, int c = 1, int l = 0, int r = maxn){
  if (l == r-1){
    seg[c] += val;
    return;
  }

  int mid = (l+r)/2;
  if (idx < mid)
    add(idx, val, c*2, l, mid);
  else
    add(idx, val, c*2+1, mid, r);
  seg[c] = seg[2*c] + seg[2*c + 1];
}

int kth(int k, int c = 1, int l = 0, int r = maxn){
  if (l == r -1)
    return seg[c]?l : -1;
  int mid = (l + r)/2;
  if (seg[2*c] >= k)
    return kth(k, c*2, l, mid);
  else
    return kth(k - seg[2*c], c*2+1, mid, r);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n, q;
  cin >> n >> q;
  
  for (int  i= 0; i < n; ++i){
    int x;
    cin >> x;
    add(x, 1);
  }

  for (int i = 0; i < q; ++i){
    int k;
    cin >> k;
    if (k < 0){
      int j = kth(-k);
      add(j, -1);
    }
    else{
      add(k, 1);
    }
  }

  int ans = kth(1);
  if (ans == -1)
    cout << 0 << endl;
  else
    cout << ans << endl;



  return 0;
}
