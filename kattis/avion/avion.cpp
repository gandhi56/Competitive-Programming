#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  vector<int> ans;
  for (int i = 0; i < 5; ++i){
    string s;
    cin >> s;
    if (s.find("FBI") != -1) ans.push_back(i);
  }

  if (ans.empty()){
    cout << "HE GOT AWAY!" << endl;
    return 0;
  }
  for (auto x : ans)  cout << x+1 << ' ';
  cout << endl;
  return 0;
}
