#include <iostream>

using namespace std;

bool fits(int w, int h, int k){
	return k*k <= w*w + h*h;
}

int main(){
	int n, w, h;
	cin >> n >> w >> h;

	while (n--){
		int u;
		cin >> u;
		if (fits(w, h, u)){
			cout << "DA" << endl;
		}else{
			cout << "NE" << endl;
		}
	}

	return 0;
}
