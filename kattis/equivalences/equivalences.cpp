#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vii;
typedef vector<bool> vb;

vii g, gr;
bitset<20010> used;
vi order;

void dfs1(int v){
    used.set(v);
    for (auto w : g[v]){
        if (!used[w])   dfs1(w);
    }
    order.push_back(v);
}

void dfs2(int v){
    used.set(v);
    for (auto w : gr[v]){
        if (!used[w])   dfs2(w);
    }
}

int main(){
    int t;
    cin >> t;

    while (t--){
        used.reset();

        int n, m;
        cin >> n >> m;

        g.resize(n, vi());
        gr.resize(n, vi());

        while (m--){
            int a, b;
            cin >> a >> b;
            g[a-1].push_back(b-1);
            gr[b-1].push_back(a-1);
        }

        used.reset();
        for (int i = 0; i < n; ++i){
            if (!used[i])   dfs1(i);
        }

        used.reset();
        int count = 0;
        for (int i = 0; i < n; ++i){
            int v = order[n-i-1];
            if (!used[v]){
                dfs2(v);
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}


