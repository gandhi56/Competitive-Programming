#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
	int n;
	while (cin >> n){

		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;

		bool svalid = true;
		bool qvalid = true;
		bool pqvalid = true;
		while (n--){
			int x, y;
			cin >> x >> y;
			if (x == 1){
				s.push(y);
				q.push(y);
				pq.push(y);
			}
			else if (x == 2){
				if (!svalid or s.empty() or y != s.top()){
					svalid = false;
				}
				else{
					s.pop();
				}
				if (!qvalid or q.empty() or y != q.front()){
					qvalid = false;
				}
				else{
					q.pop();
				}
				if (!pqvalid or pq.empty() or y != pq.top()){
					pqvalid = false;
				}
				else{
					pq.pop();
				}
			}
		}

		int v = 0;
		if (svalid)	v++;
		if (qvalid)	v++;
		if (pqvalid)	v++;

		if (v == 0){
			cout << "impossible" << endl;
		}
		else if (v == 1){
			if (svalid){
				cout << "stack" << endl;	
			}
			else if (qvalid){
				cout << "queue" << endl;
			}
			else if (pqvalid){
				cout << "priority queue" << endl;
			}
		}
		else{
			cout << "not sure" << endl;
		}

	}

	return 0;
}
