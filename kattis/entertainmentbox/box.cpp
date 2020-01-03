#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct Interval{
	int x, y;

	bool operator<(const Interval& rhs){
		return y < rhs.y;
	}
};

int main(){
	int n, k;
	cin >> n >> k;

	Interval intervals[n];
	for (int i = 0; i < n; ++i){
		cin >> intervals[i].x >> intervals[i].y;
	}

	stack<Interval> slots[k];

	sort(intervals, intervals+n);

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < k; ++j){
			if (slots[j].empty()){
				slots[j].push();
				break;
			}
			else{
				Interval prev = slots[j].top();

			}
		}
	}
	
	return 0;
}
