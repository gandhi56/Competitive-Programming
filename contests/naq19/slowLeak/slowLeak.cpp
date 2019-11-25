#include <bits/stdc++.h>
using namespace std;
 
using namespace std;
 
int n, m, t, d;
unordered_set<int> repair;
 
void fast() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
}
 
struct Edge {
  int u, v;
  int w;
  Edge (int uu, int vv, int ww) : u(uu), v(vv), w(ww) {}
 
  bool operator<(const Edge& rhs) const { return w > rhs.w; }
};
 
typedef vector<Edge> VE;
typedef pair<int,int> ii;
 
vector<VE> graph;
VE pre;
vector<VE> graph2;
VE pre2;
 
void dijkstra(int s) {
  stack< Edge > pq;
 
  pre.assign(graph.size(), Edge(-1, -1, -1));
 
  pq.push(Edge(-2, s, 0));
 
  while (!pq.empty()) {
    Edge curr = pq.top();
    pq.pop();
 
    if (pre[curr.v].v != -1) continue;
    pre[curr.v] = curr;
 
    // if (curr.w > d) {
    //   continue;
    // }
    // cout << curr.u << " " << curr.v << " " << curr.w << endl;
 
    for (auto e : graph[curr.v]) {
      if (e.w + curr.w <= d)
        pq.push(Edge(e.u, e.v, e.w + curr.w));
    }
  }
}

void ddddd(int s){
  stack<ii> stk;
  stk.push({0,s});
  bool visited[graph.size()];
  memset(visited, false, sizeof(visited));
  while (!stk.empty()){
    ii curr = stk.top();
    stk.pop();

    if (curr.first > d)
      continue;
    if (visited[curr.second])
      continue;

    if (repair.find(curr.second) != repair.end()){
      graph2[s].push_back(Edge(s, curr.second, curr.first));
      continue;
    }


    for (auto e : graph[curr.second]){
      stk.push({e.w + curr.first, e.v});
    }
  }
}
 
int get_path(int v, VE& path) {
  if (pre[v].v == -1) return -1; // no path
 
  path.clear();
 
  int len = pre[v].w;
  while (pre[v].u != -2) {
    path.push_back(Edge(pre[v].u, pre[v].v, pre[v].w - pre[pre[v].u].w));
    v = pre[v].u;
  }
 
  reverse(path.begin(), path.end());
 
  return len;
}
 
void dijkstra2(int s) {
  priority_queue< Edge > pq;
 
  pre2.assign(graph2.size(), Edge(-1, -1, -1));
 
  pq.push(Edge(-2, s, 0));
 
  while (!pq.empty()) {
    Edge curr = pq.top();
    pq.pop();
 
    if (pre2[curr.v].v != -1) continue;
 
    // cout << curr.u << " " << curr.v << " " << curr.w << endl;
 
    pre2[curr.v] = curr;
 
    for (auto e : graph2[curr.v])
      pq.push(Edge(e.u, e.v, e.w + curr.w));
  }
}
 
int get_path2(int v, VE& path) {
  if (pre2[v].v == -1) return -1; // no path
 
  path.clear();
 
  int len = pre2[v].w;
  while (pre2[v].u != -2) {
    path.push_back(Edge(pre2[v].u, pre2[v].v, pre2[v].w - pre2[pre2[v].u].w));
    v = pre2[v].u;
  }
 
  reverse(path.begin(), path.end());
 
  return len;
}
 
 
int main() {
  fast();
 
  cin >> n >> m >> t >> d;
 
  graph.assign(n+1, VE());
  graph2.assign(n+1, VE());
 
  for (int i = 0; i < t; ++i) {
    int r;
    cin >> r;
    repair.insert(r);
  }
 
 
 
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back(Edge(u,v,w));
    graph[v].push_back(Edge(v,u,w));
  }
 
  for (int s = 1; s < n; ++s) {
    if (s != 1 && repair.find(s) == repair.end()) continue;
 
    ddddd(s);
    pre.clear();
    // for (int v = 1; v < n+1; ++v) {
    //   if (s == v) continue;
    //   if (v != n && repair.find(v) == repair.end()) continue;
    //   if (pre[v].v != -1 && pre[v].w <= d) {
    //     graph2[s].push_back(Edge(s,v,pre[v].w ));
    //   }
    // }
  }
 
  // cout << "!!!!!!" << endl;
 
  dijkstra2(1);
  VE path;
  int len = get_path2(n, path);
 
  if (len == -1) {
    cout << "stuck" << endl;
  } else {
    cout << len << endl;
  }
 
  return 0;
}
