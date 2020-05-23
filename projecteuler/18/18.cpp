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

const int N = 15;

ll g[4][4] = {
      {3, 0, 0, 0},
      {7, 4, 0, 0},
      {2, 4, 6, 0},
      {8, 5, 9, 3}
      };

ll G[15][15] = {

{ 75,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 95, 64,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 17, 47, 82,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 18, 35, 87, 10,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 20,  4, 82, 47, 65,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 19,  1, 23, 75,  3, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{ 88,  2, 77, 73,  7, 63, 67,0, 0, 0, 0, 0, 0, 0, 0},
{ 99, 65,  4, 28,  6, 16, 70, 92, 0, 0, 0, 0, 0, 0, 0},
{ 41, 41, 26, 56, 83, 40, 80, 70, 33, 0, 0, 0, 0, 0, 0},
{ 41, 48, 72, 33, 47, 32, 37, 16, 94, 29, 0, 0, 0, 0, 0},
{ 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, 0, 0, 0, 0},
{ 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, 0, 0, 0},
{ 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, 0, 0},
{ 63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, 0},
{  4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23}
};

ll solve(int i, int j){
  if (i >= N) return 0;
  return G[i][j] + max(solve(i+1, j), solve(i+1, j+1));
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  cout << solve(0,0) << endl;

  return 0;
}
