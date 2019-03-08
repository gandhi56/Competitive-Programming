#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

typedef vector< vector<int> > vii;

int n, k, c;
map<string,int> id;
int color[20];

int uncolored(){
    for (int i = 0; i < n; ++i){
        if (color[i] == 0)  return i;
    }
    return -1;
}

int count(int col){
    int size = 0;
    for (int i = 0; i < n; ++i){
        if (color[i] == col)    size++;
    }
    return size;
}

bool colorable(vii& g, int u, int col){
    if (count(col) >= c)    return false;
    for (auto& v : g[u]){
        if (color[v] == col)  return false;
    }
    return true;
}

bool solve(vii& g, int k){
    int u = uncolored();
    if (u == -1)    return true;

    for (int col = 1; col <= k; ++col){
        if (!colorable(g, u, col)) continue;
        color[u] = col;
        if (solve(g, k))   return true;
        color[u] = 0;
    }
    return false;
}

void print_soln(int k){ 
    cout << k << endl;
    for (int i = 1; i <= k; ++i){
        for (auto& it : id){
            if (color[it.second] == i){
                cout << it.first << " ";
            }
        }
        cout << endl;
    }
}

void reset_colors(){
    for (int i =0 ; i < n; ++i){
        color[i] = 0;
    }
}

int main(){

    
    cin >> n >> k >> c;

    vii g(n);

    reset_colors();
    for (int i = 0; i < n; ++i){
        string name;
        cin >> name;
        id[name] = i;
    }

    while (k--){
        string a, b;
        cin >> a >> b;
        g[ id[a] ].push_back( id[b] );
        g[ id[b] ].push_back( id[a] );
    }

    int lo = 1;
    int hi = n;
    int mid;
    while (lo < hi){
        mid = (lo + hi) / 2;


        reset_colors();
        color[0] = 1;
        if (solve(g, mid)){
            hi = mid;
        }
        else{
            lo = mid+1;
        }
    }
	color[0] = 1;
    solve(g, lo);
    print_soln(lo);


    return 0;
}



