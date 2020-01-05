#include <iostream>
#include <map>
using namespace std;

int main(){
	int n;
	cin >> n;

	long ans = 0;
	map<int,int> bst;
	int node;
	cin >> node;
	bst[node] = 0;
	cout << "0" << endl;
	for (int i = 1; i < n; ++i){
		cin >> node;

		map<int,int>::iterator it = bst.lower_bound(node);
		int depth = 0;
		if (it != bst.end())	depth = it->second + 1;
		if (it != bst.begin()){
			--it;
			depth = max(depth, it->second+1);
		}
		bst[node] = depth;
		ans += depth;
		cout << ans << endl;
	}

	return 0;
}
