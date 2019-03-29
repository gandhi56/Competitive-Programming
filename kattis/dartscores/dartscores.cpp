#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int t;
	cin >> t;

	while (t--){
		int n;
		cin >> n;

		int score =0 ;
		while (n--){
			double x, y;
			cin >> x >> y;

			double dist = sqrt(x*x + y*y);
			if (dist == 0)	score--;

			while (dist <= 200){
				score++;
				dist += 20;
			}

		}
		cout << score << endl;
	}
	return 0;
}
