#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define min(a, b, c) min(a, min(b, c))
#define max(a, b, c) max(a, max(b, c))
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct interval{
  int s, t, id;
  char c;
  interval(int ss, int tt, int ii, char cc) :   s(ss), t(tt), id(ii), c(cc){}
};

bool overlap(interval& a, interval& b){
  return a.t > b.s;
}

bool cmp1(interval i1, interval i2){
  return i1.s < i2.s or (i1.s == i2.s and i1.t < i2.t);
}

bool cmp2(interval i1, interval i2){
  return i1.id < i2.id;
}

void solve(int tc){
  int n;
  cin >> n;

  vector<interval> a;
  for (int i =0; i < n; ++i){
    int s, t;
    cin >> s >> t;
    a.emplace_back(s, t, i, '?');
  }

  sort(all(a), cmp1);

  // check if impossible
  for (int i = 0; i+2 < sz(a); ++i){
    pii com = {max(a[i].s, a[i+1].s, a[i+2].s), 
                min(a[i].t, a[i+1].t, a[i+2].t)};
  
    if (com.first < com.second){
      cout << "Case #" << tc << ": IMPOSSIBLE" << endl;
      return;
    }
  }

  // find a scheduling
  a[0].c = 'C';
  for (int i = 1; i < sz(a); ++i){
    if (overlap(a[i-1], a[i])){
      a[i].c = (a[i-1].c == 'C'? 'J':'C');
    }
    else{
      a[i].c = a[i-1].c;
    }
  }

  string ans;
  sort(all(a), cmp2);
  for (auto& x : a) ans += x.c;

  cout << "Case #" << tc << ": " << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; ++tc){
    solve(tc);
  }

  return 0;
}
