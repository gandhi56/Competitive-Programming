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
 
  vi disp(k, -1);
  int idx = sz(disp) - 1;

  while (n--){
    int x;
    cin >> x;
    if (find(disp.begin(), disp.end(), x) == disp.end()){
      if (sz(disp) >= k)
        disp.pop_back();
      disp.insert(disp.begin(), x);
    }
  }

  while (!disp.empty() and disp.back() == -1)
    disp.pop_back();

  cout << disp.size() << endl;
  for (auto x : disp)
    cout << x << ' ';
  cout << endl;

  return 0;
}
