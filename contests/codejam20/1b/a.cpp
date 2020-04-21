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

const ll minc = -1000;
const ll maxc = -minc;

typedef pair<ll, ll> postype;

map<postype, postype> par;

bool ok(pair<ll,ll> pos){
  return pos.first > minc and pos.first < maxc and pos.second > minc and pos.second < maxc;
}

vector<postype> getnext(postype pos, ll dd){
  vector<postype> v;
  v.push_back({pos.first+dd, pos.second});
  v.push_back({pos.first-dd, pos.second});
  v.push_back({pos.first, pos.second+dd});
  v.push_back({pos.first, pos.second-dd});
  return v;
}

char getdir(postype curr){
  auto prev = par[curr];
  if (curr.first == prev.first){
    return (prev.second > curr.second ? 'N' : 'S');
  }
  else{
    return (prev.first > curr.first ? 'W' : 'E');
  }
}

bool pass(postype curr, postype next, postype goal){
  if (curr.first == next.first and curr.first == goal.first){
    return abs(goal.second - curr.second) < abs(goal.second - next.second);
  }
  else if (curr.second == next.second and curr.second == goal.second){
    return abs(goal.first - curr.first) < abs(goal.first - next.first);
  }
  return false;
}

void solve(int tc){
  ll x, y;
  cin >> x >> y;

  postype curr = {0,0};
  ll step = -1;

  queue< pair<postype, ll> > q;
  q.push({curr, step});

  while (!q.empty()){
    auto curr = q.front(); q.pop();
    auto currpos = curr.first;
    auto step = curr.second+1;
    if (currpos.first == x and currpos.second == y) break;
    for (auto nextpos : getnext(currpos, 1LL << step)){
      if (ok(nextpos) and par.find(nextpos) == par.end()){
        par[nextpos] = currpos;
        q.push({nextpos, step});
      }
    }
  }

  if (par.find({x, y}) == par.end()){
    cout << "Case #" << tc << ": IMPOSSIBLE" << endl;
  }
  else{
    cout << "Case #" << tc << ": ";
    string path;
    postype goal = {x, y};
    while (1){
      path.push_back(getdir(goal));
      if (goal.first == 0 and goal.second == 0){
        break;
      }
      goal = par[goal];
      // cout << goal.first << ' ' << goal.second << endl;
    }
    // reverse(all(path));
    path.pop_back();
    cout << path << endl;
  }

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; ++tc)
    solve(tc);

  return 0;
}
