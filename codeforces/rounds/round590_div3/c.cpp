#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n, k;
  cin >> n >> k;
 
  queue<int> q;
  set<int> inq;
  while (n--){
    int x;
    cin >> x;
    if (!inq.count(x)){
      if (q.size() >= k){
        inq.erase(q.front());
        q.pop();
      }
      q.push(x);
      inq.insert(x);
    }
  }

  vi ans;
  while (!q.empty()){
    ans.push_back(q.front());
    q.pop();
  }

  reverse(ans.begin(), ans.end());

  cout << sz(ans) << endl;
  for (auto x :  ans)   cout << x << ' ';
  cout << endl;

  return 0;
}
