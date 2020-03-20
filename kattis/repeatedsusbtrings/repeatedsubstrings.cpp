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

const int maxn = 100005;
char T[maxn];
int N;
int SA[maxn], tempSA[maxn];
int RA[maxn], tempRA[maxn];
int c[maxn];

void radixSort(int k){
  int i, maxi = max(300, N);
  memset(c, 0, sizeof c);
  for (i = 0; i < N; ++i)
    c[i + k < N ? RA[i+k] : 0]++;
  int sum = 0;
  for (i = 0; i < maxi; ++i){
    int t = c[i];
    c[i] = sum;
    sum += t;
  }
  for (i = 0; i < N; ++i){
    int indexToC = SA[i] + k < N ? RA[SA[i] + k] : 0;
    tempSA[c[indexToC]++] = SA[i];
  }
  for (i = 0; i < N; ++i)   SA[i] = tempSA[i];
}

void constructSA(){
  int i;
  for (i = 0; i < N; ++i)   RA[i] = T[i];
  for (i = 0; i < N; ++i)   SA[i] = i;
  for (int k = 1; k < N; k <<= 1){
    radixSort(k);
    radixSort(0);
    int r = 0;
    tempRA[SA[0]] = r;
    for (i = 1; i < N; ++i){
      tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] and RA[(SA[i] + k) % N] == RA[(SA[i-1] + k) % N]) ? r : ++r;
    }
    for (i = 0; i < N; ++i)
      RA[i] = tempRA[i];
    if (RA[SA[N-1]] == N - 1)
      break;
  }
}


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  string s;
  cin >> s;


  constructSA();

  return 0;
}
