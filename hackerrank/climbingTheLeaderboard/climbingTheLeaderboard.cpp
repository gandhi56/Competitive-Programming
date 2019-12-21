#include <bits/stdc++.h>
using namespace std;

int bsearch(vector<int>& scores, int x){
  int lo = 0;
  int hi = scores.size() - 1;
  int mid;
  if (x < scores.back())  return scores.size() + 1;
  while (lo <= hi){
    mid = (lo + hi) / 2;
    if (scores[mid] == x or (scores[mid+1] > x and scores[mid] < x))  break;
    if (scores[mid] > x){
      lo = mid + 1;
    }
    else if (scores[mid] < x){
      hi = mid - 1;
    }
    else{
      break;
    }
  }
  return mid+1;
}

int main(){
  int n;
  cin >> n;
  vector<int> scores;
  while (n--){
    int x;
    cin >> x;
    if (scores.size() and scores.back() == x)
      continue;
    scores.push_back(x);
  }

  int m;
  cin >> m;
  while (m--){
    int x;
    cin >> x;
    cout << bsearch(scores, x) << endl;
  }

  return 0;
}
