#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int a = 0, d = 0;
  for (auto c : s){
    if (c == 'A') a++;
    if (c == 'D') d++;
  }
  if (a > d){
    cout << "Anton" << endl;
  }
  else if (d > a){
    cout << "Danik" << endl;
  }
  else{
    cout << "Friendship" << endl;
  }
  return 0;
}
