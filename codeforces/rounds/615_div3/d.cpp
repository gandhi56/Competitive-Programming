#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int binsearch(vector<int>& a, int x){
  int n = a.size();
  int n = a.size();
  int lo = 0;
  int hi = n - 1;
  while (lo <= hi){
    int mid = lo + (hi - lo)/2;
    if (a[mid] == x){
      return mid;
    }
    else if (a[mid] > x){
      hi = mid - 1;
    }
    else{
      lo = mid + 1;
    }
  }
  return -1;
}

int mex(vector<int>& a){
  sort(a.begin(), a.end());
  for (int x = 0; x <= a.back()+1; ++x){
    if (binsearch(a, x) == -1)  return x;
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int q, x;
  cin >> q >> x;
  vector<int> a;
  while (q--){
    int y;
    cin >> y;
    a.push_back(y);

    int maxVal = -1;
    maxVal = max(maxVal, a.back());

    cout << maxVal+1 << endl;

  }

  return 0;
}
