#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    
    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<int>> g;

    int x;
    cin >> x;
    s.push(x);
    ll med = x;
    ll ans = med;
    n--;
    while (n--){
      cin >> x;
      if (s.size() > g.size()){
        if (x < med){
          g.push(s.top());
          s.pop();
          s.push(x);
        }
        else{
          g.push(x);
        }
        med = (s.top() + g.top())/2;
      }
      else if (s.size() == g.size()){
        if (x < med){
          s.push(x);
          med = s.top();
        }
        else{
          g.push(x);
          med = g.top();
        }
      }
      else{
        if (x > med){
          s.push(g.top());
          g.pop();
          g.push(x);
        }
        else{
          s.push(x);
        }
        med = (s.top() + g.top())/2;
      }

      ans += med;
    }

    cout << ans << endl;    


  }
  return 0;
}
