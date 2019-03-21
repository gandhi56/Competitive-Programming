#include <iostream>
using namespace std;

struct segment{
	int sx, sy, ex, ey;
};

int main(){
	int np;
	while (cin >> np){

		segment seg[np];
		for (int i =0 ; i < np; ++i){
			cin >> seg[i].sx >> seg[i].sy >> seg[i].ex >> seg[i].ey;
		}

		int q;
		cin >> q;

		while (q--){
			int x, y;
			cin >> x >> y;

			while (1){
				int j = -1;
				double max = -1, ty;

			}

		}

	}

	return 0;
}
