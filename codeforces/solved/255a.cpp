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
  int a[n];
  for (int i =0 ; i < n; ++i) cin >> a[i];
  int k = 0;
  int ex[] = {0,0,0};
  for (int i = 0; i < n; ++i){
    if (k == 0){
      ex[0] += a[i];
    }
    else if (k == 1){
      ex[1] += a[i];
    }
    else{
      ex[2] += a[i];
    }
    k = (k+1)%3;
  }

  if (ex[0] > ex[1] and ex[0] > ex[2]){
    cout << "chest" << endl;
  }
  else if (ex[1] > ex[0] and ex[1] > ex[2]){
    cout << "biceps" << endl;
  }
  else{
    cout << "back" << endl;
  }

  
  return 0;
}
