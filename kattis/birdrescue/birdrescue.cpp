#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int freq[2000000];

struct pos{
	int x, y;
	pos(){};
	pos(int a, int b):x(a), y(b){};
};

struct bird{
	int minDist, maxDist;
};

bool inrange(int a, int b, int c){
	return a <= b and b <= c;
}

int manDist(pos a, pos b){
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int getmaxdist(pos p, int x1, int y1, int x2, int y2){
	pos posList[] = {pos(x1,y1), pos(x1,y2), pos(x2,y1), pos(x2,y2)};
	int maxDist = 0;
	for (int i = 0; i < 4; ++i){
		maxDist = max(maxDist, manDist(p, posList[i]));
	}
	return maxDist;
}

int getmindist(pos p, int x1, int y1, int x2, int y2){
	if (x1 > x2)	swap(x1, x2);
	if (y1 > y2)	swap(y1, y2);
	if (inrange(x1, p.x, x2) and inrange(y1, p.y, y2)){
		return 0;
	}

	if (inrange(x1, p.x, x2)){
		return min( abs(p.y-y1), abs(p.y-y2) );
	}
	else if (inrange(y1, p.y, y2)){
		return min( abs(p.x-x1), abs(p.x-x2) );
	}
	else{
		pos posList[] = {pos(x1,y1), pos(x1,y2), pos(x2,y1), pos(x2,y2)};
		int minDist = manDist(p, posList[0]);
		for (int i = 1; i < 4; ++i){
			minDist = min(minDist, manDist(p, posList[i]));
		}
		return minDist;
	}
}

bool cmp(const bird& a, const bird& b){
	if (a.minDist == b.minDist)	return a.maxDist < b.maxDist;
	return a.minDist < b.minDist;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> n >> q;

	pos p;
	cin >> p.x >> p.y;

	bird b[n];
	for (int i = 0; i < n; ++i){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		b[i].minDist = getmindist(p, x1, y1, x2, y2);
		b[i].maxDist = getmaxdist(p, x1, y1, x2, y2);
	}

	sort(b, b+n, cmp);

	while (q--){
		int d;
		cin >> d;
		int cnt =0;

		int i = 0;
		while (i < n and d > b[i].maxDist)	i++;
		for (; i < n; ++i){
			if (inrange(b[i].minDist, d, b[i].maxDist)){
				cnt++;
			}
			if (d < b[i].minDist)	break;
		}
		cout << cnt << endl;
	}

	return 0;
}
