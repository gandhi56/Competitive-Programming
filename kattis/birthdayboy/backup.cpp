#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int totalDays(int m){
  if (m == 2) return 28;
  if (m <= 7){
    if (m&1)  return 31;
    return 30;
  }
  else{
    if (m&1)  return 30;
    return 31;
  }
}

int countDays(ii a, ii b){
  if (a.first == b.first){
    return abs(b.second - a.second);
  }
  int ans = totalDays(a.first) - a.second;
  for (int m = a.first+1; m < b.first; ++m){
    ans += totalDays(m);
  }
  ans += b.second;
  return ans;
}

void print_date(ii d){
  if (d.first < 10) cout << '0';
  cout << d.first << '-';
  if (d.second < 10) cout << '0';
  cout << d.second << endl;
}

ii prev_day(ii d){
  if (d.second > 1){
    d.second--;
    return d;
  }
  if (d.first > 1){
    d.first--;
    d.second = totalDays(d.first);
    return d;
  }
  return {12, 31};
}

bool prev_day(ii a, ii b){
  if (a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}

int main(){
  int n;
  cin >> n;

  vector<ii> dates;
  while (n--){
    string s;
    cin >> s;

    int a, b;
    char c;
    cin >> a >> c >> b;

    dates.push_back({a, b});
  }

  sort(dates.begin(), dates.end());

  ii best;
  int bestDays = 0;
  bool tie = false;
  for (int i = 0; i < dates.size()-1; ++i){
    int days = countDays(dates[i], dates[i+1]);
    if (days > bestDays){
      tie = false;
      bestDays = days;
      best = prev_day(dates[i+1]);
    }
    else if (days == bestDays){
      tie = true;
    }
  }

  // special case
  int days = 1 + countDays(dates.back(), {12, 31}) + countDays({1,1}, dates[0]);
  if (days > bestDays){
    tie = false;
    bestDays = days;
    best = prev_day(dates[0]);
  }
  else if (days == bestDays){
    tie = true;
  }

  if (!tie){
    print_date(best);
    return 0;
  }

  // find first date after oct 28
  int i;
  for (i = 0; i < dates.size(); ++i){
    if (prev_day({10, 28}, dates[i])) break;
  }
  if (i == dates.size())  i = 0;

  print_date(prev_day(dates[i]));

  return 0;
}
