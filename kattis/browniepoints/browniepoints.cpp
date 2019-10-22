#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;

	while (1){
		cin >> n;

		if (n == 0)	break;

		int s, o;
		s = 0; o = 0;

		int x[n];
		int y[n];
		for (int i =0; i< n; ++i)
			cin >> x[i] >> y[i];

		int cx = x[n/2];
		int cy = y[n/2];
		for (int i =0 ; i < n; ++i){
			if ((x[i] > cx and y[i] > cy) or (x[i] < cx and y[i] < cy)){
				s++;
			}
			else if ((x[i] > cx and y[i] < cy) or (x[i] < cx and y[i] > cy)){
				o++;
			}
		}

		cout << s << " " << o << endl;
	
	}

	return 0;
}
