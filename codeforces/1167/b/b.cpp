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

int query(int i, int j){
  cout << "? " << i << ' ' << j << endl;
  int x;
  cin >> x;
  return x;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int p[] = {4, 8, 15, 16, 23, 42};
  vi ans;

  int x = query(1, 2);
  int y = query(2, 3);
  for (int i = 0; i < 6; ++i){
    for (int j = i+1; j < 6; ++j){
      if (p[i]*p[j] == x){
        if (y%p[i] == 0){
          ans.push_back(p[i]);
          ans.push_back(p[j]);
          ans.push_back(y/p[j]);
        }
        else{
          ans.push_back(p[j]);
          ans.push_back(p[i]);
          ans.push_back(y/p[i]);
        }
        goto done;
      }
    }
  }

done:;
  x = query(4, 5);
  y = query(5, 6);
  for (int i = 0; i < 6; ++i){
    for (int j = i+1; j < 6; ++j){
      if (p[i]*p[j] == x){
        if (y%p[i] == 0){
          ans.push_back(p[j]);
          ans.push_back(p[i]);
          ans.push_back(y/p[i]);
        }
        else{
          ans.push_back(p[i]);
          ans.push_back(p[j]);
          ans.push_back(y/p[j]);
        }
        goto done2;
      }
    }
  }

  done2:;

  cout << "! ";
  for (auto x : ans) cout << x << ' ';
  cout << endl;

  return 0;
}
