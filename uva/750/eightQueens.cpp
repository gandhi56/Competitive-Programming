#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int x[9], tc, a, b, line;

bool place(int q, int r){
	for (int prev = 1; prev <= q - 1; ++prev){
		if (x[prev] == r || (abs(x[prev] - r) == abs(prev - q)))
			return false;
	}
	return true;
}

void nqueens(int q){
	for (int row = 1; row <= 8; ++row){
		if (place(q, row)){
			x[q] = row;
			if (q == 8 and x[b] == a){
				printf("%2d      %d", ++line, x[1]);
				for (int j = 2; j <= 8; ++j)	printf(" %d", x[j]);
				printf("\n");
			}
			else{
				nqueens(q+1);
			}
		}
	}
}

int main(){
	scanf("%d", &tc);
	while (tc--){
		scanf("%d %d", &a, &b);
		memset(x, 0, sizeof(x));
		line = 0;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		nqueens(1);
		if (tc)	printf("\n");
	}

	return 0;
}
