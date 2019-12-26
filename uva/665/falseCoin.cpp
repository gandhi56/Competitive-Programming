#include <iostream>
#include <vector>
using namespace std;

struct Weight{
	vector<int> leftCoins;
	vector<int> rightCoins;
	char bal;

	void print(){
		for (auto c : leftCoins){
			cout << c << " ";
		}
		cout << bal << " ";

		for (auto c : rightCoins){
			cout << c << " ";
		}
		cout << endl;
	}

	bool satisfied(int w[]){
		int l = 0, r = 0;
		for (auto c : leftCoins)	l += w[c];
		for (auto c : rightCoins)	r += w[c];
		if 		(bal == '<'){	return l < r;	}
		else if (bal == '>'){	return l > r;	}
		else				{	return l == r;	}
	}
};

void solve(vector<Weight>& weights, int n){
	// set w[i] = 1 for each coin
	int w[n+1];
	for (int i = 1; i <= n; ++i){
		w[i] = 1;
	}

	// assume no false coin exists
	int falseCoin = -1;
	bool ok = false;

	// for each coin
	for (int i = 1; i <= n; ++i){

		// increment w[i]
		w[i]++;

		// check if each constraint is satisfied
		for (auto weight : weights){
			ok = weight.satisfied(w);
			if (!ok)	break;
		}
		w[i]--;

		if (ok){
			cout << i << endl;
			return;
		}
	}
/*
	// for each coin
	for (int i = 1; i <= n; ++i){

		// increment w[i]
		w[i]--;

		// check if each constraint is satisfied
		for (auto weight : weights){
			ok = weight.satisfied(w);
			if (!ok)	break;
		}
		w[i]++;

		if (ok){
			cout << i << endl;
			return;
		}
	}
*/
	cout << "0" << endl;

}

int main(){
	int m;
	cin >> m;

	while (m--){
		int n, k;
		cin >> n >> k;


		vector<Weight> weights;
		while (k--){
			Weight w;
			int count;
			cin >> count;
			for (int i = 0; i < count; ++i){
				int val;
				cin >> val;
				w.leftCoins.push_back(val);
			}
			for (int i = 0; i < count; ++i){
				int val;
				cin >> val;
				w.rightCoins.push_back(val);
			}
			cin >> w.bal;
			weights.push_back(w);
		}

		solve(weights, n);
		if (m > 0)	cout << endl;
	}

	return 0;
}
