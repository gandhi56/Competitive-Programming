
#define maxm 200000001


#include <iostream>
#include <vector>
using namespace std;


int main(){
	int r, m;
	cin >> r >> m;

	vector<int> a;
	a.push_back(r);
	
	vector<bool> seen(maxm, false);
	seen[r] = true;

	bool found = false;
	while (!found){
		if (a.back() == m)	break;

		// compute the next value in a
		for (int d = 1; ; ++d){
			if (!seen[d]){
				// if d was not used in a before
				//cout << "d = " << d << endl;
				a.push_back(a.back() + d);
				seen[a.back()] = true;
				break;
			}
		}

		// mark all differences
		for (int i = 0; i < a.size()-1; ++i){
			seen[a.back() - a[i]] = true;
			if (a.back() - a[i] == m){
				found = true;
				break;
			}
		}

		#ifdef debug
		for (auto& x : a)
			cout << x << " ";
		cout << endl;
		#endif
	}
	cout << a.size() << endl;

	return 0;
}
