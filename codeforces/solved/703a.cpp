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

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n ;
  cin >> n;

  int m = 0, c= 0;
  while (n--){
    int x, y;
    cin >> x >> y;
    if (x > y)  m++;
    if (x < y)  c++;
  }
  if (m > c){
    cout << "Mishka" << endl;
  }
  else if (m < c){
    cout << "Chris" << endl;
  }
  else{
    cout << "Friendship is magic!^^" << endl;
  }
  
  return 0;
}
