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

map<string, int> m;

void build(){
  queue<string> q;
  for (char c = 'a'; c <= 'z'; c++)
    q.push(string(1, c));
  string s;
  int cnt = 1;
  while (!q.empty()){
    s = q.front(); q.pop();
    m[s] = cnt++;
    if (s.size() == 5)  continue;
    for (char c = s.back()+1; c <= 'z'; ++c)
      q.push(s+c);
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  

  for (char c = 'a'; c <= 'z'; ++c){
    m[string(1, c)] = (int)(c - 'a' + 1);
  } 

  build();

  string s;
  while (cin >> s){
    cout << m[s] << endl;
  }

  return 0;
}
