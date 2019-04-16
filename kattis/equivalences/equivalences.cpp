#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vii;
typedef vector<bool> vb;

bitset<20010> used;

void dfs1(vii& g, int v, vi& order){
    used.set(v);
    for (auto w : g[v]){
        if (!used[w])   dfs1(g, w, order);
    }
    order.push_back(v);
}

void dfs2(vii& gr, int v){
    used.set(v);
    for (auto w : gr[v]){
        if (!used[w])   dfs2(gr, w);
    }
}

int main(){
    int t;
    cin >> t;

    while (t--){
        used.reset();

        int n, m;
        cin >> n >> m;

		vii g(n+1), gr(n+1);
		vi order;
        while (m--){
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            gr[b].push_back(a);
        }

        used.reset();
        for (int i = 1; i <= n; ++i){
            if (!used[i])   dfs1(g, i, order);
        }

        used.reset();
        int count = 0;
        for (int i = 1; i <= n; ++i){
            int v = order[n-i];
            if (!used[v]){
                dfs2(gr, v);
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
