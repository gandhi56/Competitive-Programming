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

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n;
  cin >> n;

  vb inList(n+2, false);
  deque<int> d;
  for (int i = 0; i < n; ++i){
    int v;
    cin >> v;
    d.push_back(v);
    inList[v] = true;
  }

  priority_queue<int, vi, greater<int>> pq;
  for (int u = 1; u <= n+1; ++u)
    if (!inList[u])
      pq.push(u);

  int e = n;
  vi nodes;
  while (e--){
    int v = d.front();
    int u;
    //for (u = 1; u == v or (u <= n+1 and inList[u]); ++u){}
    while (pq.top() == v)   pq.pop();
    u = pq.top();
    pq.pop();
    if (u == n+1){
       cout << "Error" << endl;
       return 0;
    }
    nodes.pb(u);
    d.pop_front();
    d.push_back(u);
    inList[v] = false;
    inList[u] = true;
    pq.push(v);

    /*
    cout << "(" << u << ' ' << v << ")" << endl;

    for (u = 1; u <= n+1; ++u)
      cout << u << ' ' << inList[u] << endl;
    cout << endl;
    */
  }

  for (auto& x : nodes) cout << x << endl;

  return 0;
}
