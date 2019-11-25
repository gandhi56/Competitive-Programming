
#define INF 0x3f3f3f3f

#include <iostream>
using namespace std;

#define max3(a, b, c) max((a), max((b), (c)))
int main(){
	int t;
	cin >> t;

	while (t--){
		int best = INF;
		int a1, b1, a2, b2, a3, b3;
		cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;

		int ans1 = (a1+a2+a3) * max3(b1, b2, b3);
		int ans2 = (a1+a2+b3) * max3(b1, b2, a3);
		int ans3 = (a1+b2+a3) * max3(b1, a2, b3);
		int ans4 = (a1+b2+b3) * max3(b1, a2, a3);
		int ans5 = (b1+a2+a3) * max3(a1, b2, b3);
		int ans6 = (b1+a2+b3) * max3(a1, b2, a3);
		int ans7 = (b1+b2+a3) * max3(a1, a2, b3);
		int ans8 = (b1+b2+b3) * max3(a1, a2, a3);

		int ans9 = (b1+max(b2,b3)) * max3(a1+a2, a1+a3, a2+a3);
		int ans10 = (b2+max(b1,b3)) * max3(a1+a2, a1+a3, a2+a3);
		int ans11 = (b3+max(b1,b2)) * max3(a1+a2, a1+a3, a2+a3);
		
		int ans12 = (a1+max(b2,b3)) * max3(b1+a2, b1+a3, a2+a3);
		int ans13 = (a2+max(b1,b3)) * max3(a1+b2, a1+a3, b2+a3);
		int ans14 = (a3+max(b1,b2)) * max3(a1+a2, a1+b3, a2+b3);
		
		int ans15 = (b1+max(a2,b3)) * max3(a1+a2, a1+a3, a2+a3);
		int ans16 = (b2+max(a1,b3)) * max3(a1+a2, a1+a3, a2+a3);
		int ans17 = (b3+max(a1,b2)) * max3(a1+a2, a1+a3, a2+a3);
		best = min(ans1, ans2);
		best = min(best, ans3);
		best = min(best, ans4);
		best = min(best, ans5);
		best = min(best, ans6);
		best = min(best, ans7);
		best = min(best, ans8);
		best = min(best, ans9);
		best = min(best, ans10);
		best = min(best, ans11);
		best = min(best, ans12);
		best = min(best, ans13);
		best = min(best, ans14);

		cout << best << endl;
	}

	return 0;
}
