#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;

	priority_queue<int> pq;
	for (int i =0 ; i < n; ++i){
		int t;
		cin >> t;
		pq.push(t);
	}

	int day = 1;
	int maxDays = 0;
	while (!pq.empty()){
		int days = pq.top(); pq.pop();
		maxDays = max(maxDays, days + day);
		day++;
	}
	cout << maxDays+1 << endl;

	return 0;
}
