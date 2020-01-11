#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000

int main(){
	int n;
  cin >> n;

  bool used[n+1];
  memset(used, false, sizeof(used));

  vector<int> pi;
  for (int i = 0; i < n; ++i){
    int x;
    cin >> x;
    pi.push_back(x);
    used[x] = true;
  }

  for (int i = 0; i < n; ++i){
    if (pi[i] != 0) continue;
    int j;
    for (j = 1; j <= n; ++j){
      if (!used[j] and j != i) break;
    }
    pi[i] = j;
    used[j] = true;
  }

  for (auto x : pi){
    cout << x << ' ';
  }
  cout << endl;


  return 0;
}
