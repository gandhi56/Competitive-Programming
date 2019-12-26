#include <iostream>
using namespace std;

int main(){
	int n, l;
	cin >> n >> l;

	int d[n], r[n], g[n];
	for (int i = 0; i < n; ++i){
		cin >> d[i] >> r[i] >> g[i];
	}

	int lastdist = 0;
	int dist = 0;
	int time = 0;
	for (int i = 0; i < n; ++i){
		dist += d[i] - lastdist;
		time += d[i] - lastdist;
		int ready = (time / (r[i] + g[i])) * (r[i] + g[i]) + r[i];
		while (time < ready)	++time;
		lastdist = d[i];
	}
	time += l - lastdist;
	cout << time << endl;


	return 0;
}
