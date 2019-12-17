#include <iostream>
#include <map>
using namespace std;

struct pokemon{
	int x, y;
	string name;
};

void solve(pokemon p[], int n){
	
}

int main(){
	int n;
	cin >> n;

	pokemon p[n];
	map<string,bool> pokeNames;
	for (int i = 0; i < n; ++i){
		cin >> p[i].x >> p[i].y >> p[i].name;
		if (pokeNames.count(p[i].name) == 0){
			pokeNames.insert(pair<string,bool>(p[i].name, false));
		}
	}

	solve(p, n);

	return 0;
}
