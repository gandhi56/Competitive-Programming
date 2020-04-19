#define LIN cout << __LINE__ << endl;
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

struct Node{
  int depth, cnt;
  vector<Node*> nxt;
  Node(){
    cnt = 0;
    nxt.resize(26, nullptr);
  }
};

int n, k;
ll ans;

int dfs(Node* u){
  int cnt = u->cnt;
  for (int i = 0; i < 26; ++i)
    if (u->nxt[i] != nullptr)
      cnt += dfs(u->nxt[i]);
  ans += (cnt/k) * u->depth;
  return cnt % k;
}

int solve(){
  ans = 0;
  cin >> n >> k;

  Node rt;
  rt.depth = 0;

  for (int i = 0; i < n; ++i){
    string s;
    cin >> s;
    
    Node* cur = &rt;
    for(int j = 0; j < s.size(); ++j){
      if (cur->nxt[s[j] - 'A'] == nullptr){
        cur->nxt[s[j] - 'A'] = new Node();
        cur->nxt[s[j] - 'A']->depth = cur->depth + 1;
      }
      cur = cur->nxt[s[j] - 'A'];
    }
    cur->cnt++;
  }

  dfs(&rt);
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; ++tc)
    cout << "Case #" << tc << ": " << solve() << endl;
  
  return 0;
}
