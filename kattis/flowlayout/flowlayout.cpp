#include <bits/stdc++.h>
using namespace std;

int main(){
	int m;
	while (cin >> m and m){
		// m = max width
		int w = 0, h = 0;
		int currWidth = 0, currHeight = 0;
		int rw, rh;
		while (cin >> rw >> rh){
			if (rw == -1 and rh == -1)	break;
			if (w+rw <= m){
				h = max(h, rh);
				if (w+rw <= currWidth){
					w += rw;
				}
				else{
					w += rw;
					currWidth = w;

				}
			}
			else{
				w = rw;
				currHeight += h;
				h = rh;
			}
			//cout << "currheight = " << currHeight << endl;
		}
		currHeight += h;
		cout << currWidth << " x " << currHeight << endl;
	}
	return 0;
}
