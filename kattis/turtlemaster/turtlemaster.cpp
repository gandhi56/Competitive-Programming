#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

enum dir{RIGHT, DOWN, LEFT, UP};

char grid[8][8];

ii next_pos(ii curr, dir d){
  if (d == RIGHT)       return {curr.first, curr.second+1};
  if (d == LEFT)       return {curr.first, curr.second-1};
  if (d == DOWN)       return {curr.first+1, curr.second};
  if (d == UP)       return {curr.first-1, curr.second};
}

dir next_dir_right(dir d){
  if (d == RIGHT)       return DOWN;
  if (d == LEFT)        return UP;
  if (d == DOWN)        return LEFT;
  if (d == UP)          return RIGHT;
}
dir next_dir_left(dir d){
  if (d == RIGHT)       return UP;
  if (d == LEFT)        return DOWN;
  if (d == DOWN)        return RIGHT;
  if (d == UP)          return LEFT;
}

bool ok(ii pos){
  return pos.first >= 0 and pos.first < 8 and pos.second >= 0 and pos.second < 8;
}

int main(){
  for (int i = 0; i < 8; ++i){
    string s ;
    cin >> s;
    for (int j = 0; j < 8; ++j) grid[i][j] = s[j];
  }

  string p;
  cin >> p;

  ii pos = {7, 0};
  dir d = RIGHT;
  for (auto c : p){
    if (c == 'F'){
      ii next = next_pos(pos, d);
      if (!ok(next) or grid[next.first][next.second] == 'C' or grid[next.first][next.second] == 'I'){
        cout << "Bug!" << endl;
        return 0;
      }
      pos = next;
    }
    else if (c == 'L'){
      d = next_dir_left(d);
    }
    else if (c == 'R'){
      d = next_dir_right(d);
    }
    else if (c == 'X'){
      ii next = next_pos(pos, d);
      if (grid[next.first][next.second] == 'I'){
        grid[next.first][next.second] = '.';
      }
      else{
        cout << "Bug!" << endl;
        return 0;
      }

    }
  }

  if (grid[pos.first][pos.second] == 'D'){
    cout << "Diamond!" << endl;
  }
  else{
    cout << "Bug!" << endl;
  }

  return 0;
}
