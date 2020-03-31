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

int solve(int a, int b){
  int ans = a +  b;
  int da[] = {a/10, a%10};
  int db[] = {b/10, b%10};

  //cout << da[1] << da[0] << endl;
  //cout << db[1] << db[0] << endl;

  //cout << endl;
  if (a < 10){
    int x[] = { da[1] + db[1]*10 + db[0], 
                db[1] + da[1]*10 + db[0],
                db[0] + db[1]*10 + da[1]};
    //for (int i =0 ; i < 3; ++i) cout << x[i] << endl;
    
    
    return *max_element(x, x+3);
  }

  int x[4];
  x[0] = da[1]*10 + db[1] + da[0]*10 + db[0];
  x[1] = db[1]*10 + da[0] + da[1]*10 + db[0];
  x[2] = db[0]*10 + da[0] + db[1]*10 + da[1];
  x[3] = da[1]*10 + db[0] + db[1]*10 + da[0];

  return max(a+b, *max_element(x, x+4));
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while (t--){
    int a, b;
    cin >> a >> b;

    if (a > b)
      swap(a, b);

    cout << solve(a, b) << endl;

  }
  
  return 0;
}
