#include <iostream>
using namespace std;

struct plat{
	int y, x1, x2;
	plat(){}
	bool operator<(const plat& rhs){
		return y < rhs.y;
	}
};
int n;
plat pform[101];

inline bool inbetween(int a, int b, int c){
	return a <= b and b <= c;
}

int getPillarLen(int i){
	// left pillar, x1
	int totalLen =0;
	int minY = pform[i].y;
	for (int j = 0; j < n; ++j){
		int diff = pform[i].y - pform[j].y;
		if (diff>0 and inbetween(pform[j].x1, pform[i].x1, pform[j].x2)){
			minY = min(minY, diff);
		}
	}
	totalLen += minY;
	
	minY = pform[i].y;
	for (int j = 0; j < n; ++j){
		int diff = pform[i].y - pform[j].y;
		if (diff>0 and inbetween(pform[j].x1, pform[i].x2, pform[j].x2)){
			minY = min(minY, diff);
		}
	}
	totalLen += minY;
	return totalLen;
}

int main(){
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0 ;i < n; ++i){
		cin >> pform[i].y >> pform[i].x1 >> pform[i].x2;
		pform[i].x2--;
	}

	int len = 0;
	for (int i = 0; i < n; ++i){
		len += getPillarLen(i);
	}

	cout << len << endl;


	return 0;
}
