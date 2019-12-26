
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <climits>
using namespace std;

typedef vector< vector<int> > tree;

struct Node{
    int value;
    int rootSum;
    vector<int> children;
};

int sum(tree& t, int u, int v, int* value){
	bool visited[t.size()];
	memset(visited, false, t.size());

	int total = 0;
	stack<int> s;
	s.push(u);
	visited[u] = true;
	while (!s.empty()){
		int curr = s.top();
		s.pop();

		total += value[curr];

		for (int adj : t[curr]){
			if (!visited[adj]){
				if (curr == u and adj == v)	continue;
                if (curr == v and adj == u) continue;
				visited[adj] = true;
				s.push(adj);
			}
		}
	}

	return total;

}

int solve(tree& t, int* value){
    int minDiff = INT_MAX;
    int total = sum(t, 1, 1, value);
	for (int u = 1; u < t.size(); ++u){
		for (int v : t[u]){
			if (v < u)	continue;
			int sum1 = sum(t, u, v, value);
            int sum2 = total - sum1;
			minDiff = min(minDiff, abs(sum1-sum2));
		}
	}
	return minDiff;
}

void dfsLoop(vector<Node>& t, int u, bool* visited){
	visited[u] = true;
	for (int v : t[u].children){
		if (!visited[v]){
			dfsLoop(t, v, visited);
		}
	}

	for (int v : t[u].children){
		cout << u << "-" << v << endl;
		t[u].rootSum += t[v].rootSum;
	}

	cout << u << "->" << t[u].rootSum << endl;

}

void dfs(vector<Node>& t, int r){
	bool visited[t.size()];
	memset(visited, false, t.size());

	dfsLoop(t, r, visited);

	for (int u = 1; u < t.size(); ++u){
		cout << t[u].rootSum << " ";
	}
	cout << endl;

}

int solve(vector<Node>& t){
	// run dfs to store all subtree sums
	dfs(t, 1);
	int minDiff = INT_MAX;
	for (int u = 1; u < t.size(); ++u){
		for (int v : t[u].children){
			int sum1 = t[v].rootSum;
			int sum2 = t[1].rootSum - sum1;
			cout << u << "-" << v << ":";
			cout << sum1 << "," << sum2 << endl;
			minDiff = min(minDiff, abs(sum1-sum2));
		}
	}

	return minDiff;
}


int main(){
/*
	int n;
	cin >> n;

	tree t(n+1);
	int value[n+1];

	for (int i = 1; i <= n; ++i){
		cin >> value[i];
	}

	for (int i = 1; i < n; ++i){
		int u, v;
		cin >> u >> v;
		t[u].push_back(v);
		t[v].push_back(u);
	}


	cout << solve(t, value) << endl;
*/

	int n;
	cin >> n;

	vector<Node> t(n+1);
	for (int i = 1; i < n+1; ++i){
		int value;
		cin >> value;
		t[i].value = value;
		t[i].rootSum = value;
	}

	for (int i = 1; i < n; ++i){
		int u, v;
		cin >> u >> v;
		t[u].children.push_back(v);
		t[v].children.push_back(u);
	}

	cout << solve(t) << endl;

	return 0;
}

