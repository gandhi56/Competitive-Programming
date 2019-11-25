#include <iostream>
#include <climits>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;

		int best = -1000000000;
		int result = -1000000000;

		int m;
		while (n--){
			cin >> m;
			if (best - m > result){
				result = best - m;
			}

			if (m > best){
				best = m;
			}
		}

		cout << result << endl;

	}

	return 0;
}
