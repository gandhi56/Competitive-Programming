#include <iostream>
#include <bitset>
#include <set>
using namespace std;

#define MAXN 400001

int main(){
	int m;
	cin >> m;

	bitset<MAXN> cube;
	cube.reset();
	for (int i = 0; i*i*i < MAXN; ++i){
		cube.set(i*i*i);
	}

	set<int> a;
	bool done = false;
	int num;
	for (int x = m; x >= 1 and !done; --x){
		a.clear();
		for (int i = 1; 2*i*i*i <= x and !done; ++i){
			if (cube[i*i*i] and cube[x-(i*i*i)]){
				a.insert(i*i*i);
				if (a.size() >= 2){
					done = true;
					num = x;
					break;
				}
			}
		}
	}

	if (done){
		cout << num << endl;
	}
	else{
		cout << "none" << endl;
	}

	return 0;
}
