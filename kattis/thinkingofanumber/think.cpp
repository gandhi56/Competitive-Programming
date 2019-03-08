#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
	int n;
	while (cin >> n){
		if (n == 0)	break;

		int lo = 1;
		int hi = INT_MAX;

		string a, b;
		int i;
		vector<int> divs;
		
		while (n--){
			cin >> a >> b >> i;
			if (a == "greater"){
				lo = max(lo, i + 1);
			}
			else if (a == "less"){
				hi = min(hi, i - 1);
			}
			else if (a == "divisible"){
				divs.push_back(i);
			}
		}

		if (hi == INT_MAX){
			cout << "infinite";
		}
		else if (lo > hi){
			cout << "none";
		}
		else{
			int count = 0;
			for (int k = lo; k <= hi; ++k){
				bool ok = true;
				for (auto d : divs){
					if (k%d != 0){
						ok = false;
						break;
					}
				}

				if (ok){
					cout << k << " ";
					count++;
				}
			}
			if (count == 0){
				cout << "none";
			}
		}

		cout << endl;

	}

	return 0;
}
