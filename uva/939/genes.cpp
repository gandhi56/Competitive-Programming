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

map<string,string> gene;
map<string, vector<string>> par;
const string dom = "dominant";
const string rec = "recessive";
const string ne = "non-existent";

void solve(string c){
  string par1 = par[c][0];
  string par2 = par[c][1];
  if (gene.find(par1) == gene.end())
    solve(par1);
  if (gene.find(par2) == gene.end())
    solve(par2);

  bool hasGene = false;
  if (gene[par1] != ne and gene[par2] != ne){
    hasGene = true;
  }
  else if (gene[par1] == dom or gene[par2] == dom){
    hasGene = true;
  }

  if (!hasGene){
    gene[c] = ne;
    return;
  }
  if (gene[par1] == dom and gene[par2] == dom){
    gene[c] = dom;
  }
  else if (gene[par1] == dom and gene[par2] == rec){
    gene[c] = dom;
  }
  else if (gene[par1] == rec and gene[par2] == dom){
    gene[c] = dom;
  }
  else{
    gene[c] = rec;
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n;
  cin >> n;

  string a, b;
  while (n--){
    cin >> a >> b;
    if (b == dom or b == rec or b == ne){
      gene[a] = b;
    }
    else{
      par[b].pb(a);
    }
  }

  for (auto it = par.begin(); it != par.end(); ++it)
    solve(it->first);

  for (auto x : gene)
    cout << x.first << ' ' << x.second << endl;
  
  return 0;
}
