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

int n, K;
vi p, pos;

void swp3(int i, int j, int k){
  int a = p[i], b = p[j], c = p[k];
  //cout << "swapping " << a << ' ' << b << ' ' << c << endl;
  p[i] = c;
  p[j] = a;
  p[k] = b;
  pos[c] = i;
  pos[a] = j;
  pos[b] = k;
}

void show(){
  for (auto& x : p) cout << x+1 << ' ';
  cout << endl;
}

bool ok(){
  for (int i = 0; i < n; ++i){
    if (p[i] != i)  return false;
  }
  return true;
}

void solve(){
  cin >> n >> K;
  p.resize(0);
  p.resize(n);
  pos.resize(0);
  pos.resize(n);
  for (auto& x : p) {
    cin >> x;
    --x;
  }
  for (int i = 0 ; i < n; ++i){
    pos[p[i]] = i;
  }

  //show();
  int cnt = 0;
  vector<tuple<int,int,int>> ans;
  int i =0, j, k;
  while (1){
    for (; i < n and p[i] == i; ++i){}
    for (j = i+1; j < n and p[j] == j; ++j){}
    for (k = j+1; k < n and p[k] == k; ++k){}

    if (i == n){
      // done
      break;
    }
    else{
      if (j == n or k == n){
        cout << -1 << endl;
        return;
      }
    }

    //cout << "i = " << i << endl;
    //cout << "j = " << j << endl;
    //cout << "k = " << k << endl;

    if (!(p[i] < p[j] and p[j] < p[k])){
      swp3(i, j, k);
      ans.push_back(make_tuple(i, j, k));
    }

  }

  if (!ok() or sz(ans) > K){
    cout << -1 << endl;
    return;
  }
  cout << sz(ans) << endl;
  for (auto x : ans){
    cout << get<0>(x)+1 << ' ' << get<1>(x)+1 << ' ' << get<2>(x)+1 << endl;
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
