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
#define sq(x) (int)(x*x)
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 100;
ll dp[200][200];
vector<vi> v(100);

ll solve(int i, int j){
  if (i >= maxn)  return 0;
  if (dp[i][j])   return dp[i][j];
  return dp[i][j] = v[i][j] + max(solve(i+1, j), solve(i+1, j+1));
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  ifstream file;
  string line;
  file.open("p067_triangle.txt");
  int row = 0;
  while (getline(file, line)){
    stringstream ss;
    ss << line;
    int x;
    string tmp;
    while (!ss.eof()){
      ss >> tmp;
      if (stringstream(tmp) >> x)
        v[row].push_back(x);
      tmp = "";
    }
    while (sz(v[row]) < 100)
      v[row].push_back(0);
    row++;
  }

  memset(dp, 0, sizeof(dp));
  cout << solve(0,0) << endl;



  return 0;
}
