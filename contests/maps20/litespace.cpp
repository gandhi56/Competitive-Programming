#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s; cin >> s;
  stack<int> st;
  int i =0 ;
  string s2, s3, s4;
  while (i < sz(s)){
    //cout << i << endl;
    s2 = "";
    s3 = "";
    s4 = "";
    if (i+1 < sz(s))    s2 = s.substr(i, 2);
    if (i+2 < sz(s))    s3 = s.substr(i, 3);
    if (i+3 < sz(s))    s4 = s.substr(i, 4);

    //cout << i << endl;
    //cout << "s4 = " << s4 << endl;
    if (s2 == "SS"){
      i += 2;

      int x = 0;
      bool neg = (s[i++] == 'T');

      while (i < sz(s) and s[i] != 'N'){
        if (s[i] == 'T')
          x |= 1;
        x <<= 1;
        i++;
      }
      x >>= 1;
      i++;

      if (neg)  x *= -1;
      st.push(x);
    }
    else if (s3 == "SNS"){
      i += 3;
      if (st.empty()){
        cout << "Invalid copy operation" << endl;
        continue;
      }
      st.push(st.top());
    }
    else if (s3 == "SNT"){
      i += 3;
      if (st.size() < 2){
        cout << "Invalid swap operation" << endl;
        continue;
      }
      int x = st.top(); st.pop();
      int y = st.top(); st.pop();
      st.push(x);
      st.push(y);
    }
    else if (s3 == "SNN"){
      i += 3;
      if (st.empty()){
        cout << "Invalid remove operation" << endl;
        continue;
      }
      st.pop();
    }
    else if (s4 == "TSSS"){
      i += 4;
      if (st.size() < 2){
        cout << "Invalid addition operation" << endl;
        continue;
      }
      int x = st.top(); st.pop();
      int y = st.top(); st.pop();
      st.push(x+y);
    }
    else if (s4 == "TSST"){
      i += 4;
      
      if (st.size() < 2){
        cout << "Invalid subtraction operation" << endl;
        continue;
      }
      int x = st.top(); st.pop();
      int y = st.top(); st.pop();
      st.push(y-x);
    }
    else if (s4 == "TSSN"){
      i += 4;
      if (st.size() < 2){
        cout << "Invalid multiplication operation" << endl;
        continue;
      }
      int x = st.top(); st.pop();
      int y = st.top(); st.pop();
      st.push(x*y);
    }
    else if (s4 == "TSTS"){
      i += 4;
      if (st.size() < 2){
        cout << "Invalid division operation" << endl;
        continue;
      }
      int x = st.top(); st.pop();
      int y = st.top(); st.pop();
      if (x == 0){
        cout << "Division by zero" << endl;
        st.push(y);
        st.push(x);
        continue;
      }
      st.push(y/x);
    }
    else if (s4 == "TNST"){
      i += 4;
      if (st.empty()){
        cout << "Invalid print operation" << endl;
        continue;
      }
      int x = st.top(); st.pop();
      cout << x << endl;
    }
  }

  return 0;
}
