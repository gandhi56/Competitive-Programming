#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) { numSets--;
      int x = findSet(i), y = findSet(j);
      // rank is used to keep the tree short
      if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
      else                   { p[x] = y; setSize[y] += setSize[x];
                               if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main(){
	int t;
	cin >> t;

	while (t--){
		int n, m;
		cin >> n >> m;

		UnionFind uf(n+1);

		for (int i =0 ; i < m; ++i){
			int u, v;
			cin >> u >> v;
			uf.unionSet(u, v);
		}

		int largest = 0;
		for (int i = 1; i <= n; ++i){
			largest = max(largest, uf.sizeOfSet(i));
		}
		cout << largest << endl;

	}

	return 0;
}
