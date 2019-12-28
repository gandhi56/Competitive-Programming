#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> tree;

void init_segment_tree(int n){
	int len = (int)(2 * pow(2.0, floor(log((double)n)/log(2.0))+1));
	tree.resize(len, 0);
}

void build_segment_tree(int arr[], int node, int b, int e){
	if (b == e){
		tree[node] = arr[b];
	}
	else{
		int left = 2 * node;
		int right = 2*node + 1;
		build_segment_tree(arr, left, b, (b+e) / 2);
		build_segment_tree(arr, right, (b+e)/2 + 1, e);

		tree[node] = tree[left] + tree[right];
	}
}

int query(int arr[], int node, int b, int e, int i, int j){
	if (i > e or j < b){
		return -1;
	}
	if (b >= i and e <= j){
		return tree[node];
	}

	int p1 = query(arr, 2*node, b, (b+e)/2, i, j);
	int p2 = query(arr, 2*node+1, (b+e)/2+1, e, i, j);

	if (p1 == -1){
		return p2;
	}
	if (p2 == -1){
		return p1;
	}

	return p1+p2;
}


int main(){
	int n, q;
	cin >> n >> q;

	init_segment_tree(n+1);

	while (q--){
		char op;
		cin >> op;

		if (op == '+'){
			int i, d;
			cin >> i >> d;

			
		}
	}

	return 0;
}

