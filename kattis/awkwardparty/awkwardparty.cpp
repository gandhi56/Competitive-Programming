#include <iostream>
#include <unordered_map>
using namespace std;

#define INF 1000000001

int main(){
	int n;
	cin  >> n;

	unordered_map<int,int> p;
	int awk = n;
	for (int i = 0; i < n; ++i){
		int num;
		cin >> num;
		if (p.find(num) != p.end()){
			awk = min(awk, i - p[num]);
		}
		p[num] = i;
	}

	cout << awk << endl;

	return 0;
}
