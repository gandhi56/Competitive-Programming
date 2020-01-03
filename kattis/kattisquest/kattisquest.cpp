#include <cstdio>
#include <queue>
#include <map>
#include <cstring>
using namespace std;
int main(){
    int n;
	scanf("%d", &n);
    map<int,priority_queue<int>> poolmap;
    while (n--){
		char q[6];
		scanf("%s", q);
        if (!strcmp(q, "add")){
            int e, g;
			scanf("%d %d", &e, &g);
            poolmap[e].push(g); // logn
        }
        else{
            // - find the largest energy quest from the current pool which 
            // is smaller or equal to x
            // - clear the quest, removing it from the current pool. 
            // reduce energy of the quest and add up the gold reward earned
            // repeat
            int x, g = 0;
			scanf("%d", &x);
            while (x and !poolmap.empty()){
                map<int, priority_queue<int>>::iterator it;
                int xx = x;
                for (xx = x; xx; --xx){
                    it = poolmap.find(xx);
                    if (it != poolmap.end())    break;
                }
                if (it == poolmap.end())    break;
                x -= it->first;
                g += it->second.top();
                it->second.pop();
                if (it->second.size() == 0) poolmap.erase(it);
            }
			printf("%d\n", g);
        }
    }
    return 0;
}


