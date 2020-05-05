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

int n, k;
vi p, pos;

void swp3(int i, int j, int k){
  int a = p[i], b = p[j], c = p[k];
  p[i] = c;
  p[j] = a;
  p[k] = b;
  pos[c] = i;
  pos[a] = j;
  pos[b] = k;
}

void show(){
  for (auto& x : p) cout << x << ' ';
  cout << endl;
}

bool ok(){
  for (int i = 0; i < n; ++i){
    if (p[i] != i)  return false;
  }
  return true;
}

void solve(){
  cin >> n >> k;
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

  int inv =0 ;
  for (int i = 0; i < n; ++i){
    for (int j = i+1; j < n; ++j){
      if (p[i] > p[j])  inv++;
    }
  }
  if (inv&1){
    cout << -1 << endl;
    return;
  }

  //show();
  int cnt = 0;
  vector<tuple<int,int,int>> ans;
  for (int i = 0; i < n; ++i){
    if (p[i] == i)    continue;
    int j = pos[i];
    if (j >= n){
      cout <<-1 << endl;
      return;
    }
    if (abs(j-i) == 1){
      swp3(i, i+1, i+2);
      swp3(i, i+1, i+2);
      cnt++;
      ans.push_back(make_tuple(i, i+1, i+2));
      ans.push_back(make_tuple(i, i+1, i+2));
    }
    else{
      swp3(i, j-1, j);
      ans.push_back(make_tuple(i, j-1, j));
    }
    cnt++;
    //show();
  }

  if (!ok() or cnt > k){
    cout << -1 << endl;
    return;
  }
  cout << cnt << endl;
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
