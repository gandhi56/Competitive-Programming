#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int days[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int mtd(int m, int d){
  int val = d;
  for (int i = 1; i < m; ++i)  val += days[i];
  return val;
}

ii dtm(int val){
  int m = 1;
  while (1){
    if (val - days[m] > 0){
      val -= days[m];
      m++;
      if (m == 13)  m = 1;
    }
    else{
      break;
    }
  }
  if (val == 0){
    m--;
    if (m < 1)  m = 12;
    val = days[m];
  }
  return {m, val};
}

void print_date(ii d){
  if (d.first < 10) cout << '0';
  cout << d.first << '-';
  if (d.second < 10)  cout << '0';
  cout << d.second << endl;
}

int main(){
  int n;
  cin >> n;

  int date[n];
  for (int i = 0; i < n; ++i){
    string s;
    int m, d;
    char c;
    cin >> s >> m >> c >> d;
    date[i] = mtd(m, d);
  }

  sort(date, date+n);

  // find the longest gap
  int longestGap = 0;
  int idx;
  bool tie = false;
  int gap;
  for (int i = 0; i < n-1; ++i){
    gap = date[i+1] - date[i];
    if (gap > longestGap){
      tie = false;
      longestGap = gap;
      idx = i;
    }
    else if (gap == longestGap){
      tie = true;
    }
  }
  gap = 1 + (mtd(12, 31) - date[n-1]) + (date[0] - mtd(1,1));
  if (gap > longestGap){
    longestGap = gap;
    tie = false;
    idx = n-1;
  }
  else if (gap == longestGap){
    tie = true;
  }

  if (!tie){
    print_date(dtm(date[(idx+1)%n]-1));
    return 0;
  }

  // tie
  for (idx = 0; idx < n-1; ++idx){
    if (mtd(10, 28) <= date[idx+1]-1 and date[idx+1] - date[idx] == longestGap) break;
  }
  print_date(dtm(date[(idx+1)%n]-1));

  return 0;
}
