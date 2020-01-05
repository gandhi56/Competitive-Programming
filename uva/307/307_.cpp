#include <stdio.h>
#include <algorithm>
#include <functional>
using namespace std;
int a[101], goal, m, flag, n;
int used[101] = {}, b[101];
int dfs(int index, int st, int sum, int tm) {
    if(sum == goal) {
        if(tm+1 == m) return 1;
        if(dfs(0, 1, 0, tm+1))	return 1;
        return 0;
    }
    if(st == 1) {
        int i = 0;
        while (used[i]) i++;
        used[i] = 1;
        if(dfs(i+1, 0, a[i], tm))
            return 1;
        used[i] = 0;
    } else {
        int i;
        for(i = index; i < n; i++) {
            if(used[i]==0 && sum+a[i]<=goal && sum+b[i]>=goal) {
                if(i && a[i] == a[i-1] && used[i-1] == 0)
                    continue;
                used[i] = 1;
                if(dfs(i+1, 0, sum+a[i], tm))
                    return 1;
                used[i] = 0;
                if(sum+a[i] == goal)
                    return 0;
            }
        }
    }
    return 0;
}
int main() {
    int i;
    while(scanf("%d", &n) == 1 && n) {
        int sum = 0;
        for(i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
            used[i] = 0;
        }

		// sort a in nonincreasing order
        sort(a, a+n, greater<int>());
        
		for(i = n-1, b[n] = 0; i >= 0; i--)
            b[i] = b[i+1]+a[i];

        int L = a[0];
        flag = 0;
        for(; L <= sum/2; L++) {
            if(sum%L)   continue;
            goal = L;
            m = sum/L;
            flag = dfs(0,1,0,0);
            if(flag)    break;
        }
        if(!flag)   goal = sum;
        printf("%d\n", goal);
    }
    return 0;
}
