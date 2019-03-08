#include <iostream>
#include <algorithm>
using namespace std;

struct job{
	int id;
	int fine, time;
};

bool cmp(job& i, job& j){
	double ri = (double)i.fine / i.time;
	double rj = (double)j.fine / j.time;
	if (ri != rj)	return ri > rj;
	return i.id < j.id;
}

int main(){
	int t;
	cin >> t;

	while (t--){
		int n;
		cin >> n;

		job jobs[n];
		for (int i =0 ; i < n; ++i){
			jobs[i].id = i + 1;
			cin >> jobs[i].time >> jobs[i].fine;
		}

		sort(jobs, jobs+n, cmp);

		for (int i = 0; i < n; ++i){
			cout << jobs[i].id;
			if (i < n-1)	cout << " ";
		}
		cout << endl;

		if (t > 0)	cout << endl;

	}

	return 0;
}
