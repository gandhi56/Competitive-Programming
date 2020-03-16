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

struct FenwickTree{
  vi bit;
  int n;
  FenwickTree(int n){
    this->n = n;
    bit.assign(n, 0);
  }

  FenwickTree(vi a) : FenwickTree(a.size()) {
    for (size_t i = 0; i < a.size(); ++i)
      add(i, a[i]);
  }

  int sum(int r){
    int ret = 0;
    for (; r >= 0; r = (r & (r+1)) - 1)
      ret += bit[r];
    return ret;
  }

  int sum(int l, int r){
    return sum(r) - sum(l-1);
  }

  void add(int idx, int delta){
    for (; idx < n; idx = idx | (idx + 1))
      bit[idx] += delta;
  }
};


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n;
  cin >> n;

  FenwickTree ft(n+1);
  vi arr(n+1);
  for (int i = 1; i <= n; ++i){
    int x;
    cin >> x;
    arr[x] = i;
    ft.add(i, 1);
  }

  int l = 1, r = n;
  for (int i = 1; i <= n; ++i){
    if (i&1){
      ft.add(arr[l], -1);
      cout << ft.sum(1, arr[l]) << endl;
      l++;
    }
    else{
      ft.add(arr[r], -1);
      cout << ft.sum(arr[r], n) << endl;
      r--;
    }
  }
  
  return 0;
}
