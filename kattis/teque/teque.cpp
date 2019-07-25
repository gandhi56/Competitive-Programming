#include <stdio.h>
#include <deque>
#include <cstring>
using namespace std;

int main(){

    int n;

    scanf("%d", &n);

    deque<int> l, r;

    while (n--){
        char q[20];
        int x;

        scanf("%s %d", q, &x);
        if (strcmp(q, "push_back") == 0){
            r.push_back(x);
			if (r.size() > l.size()){
				l.push_back(r.front());
				r.pop_front();
			}
        }
        else if (strcmp(q, "push_front") == 0){
            l.push_front(x);
			if (l.size() > r.size()){
				r.push_front(l.back());
				l.pop_back();
			}
        }
        else if (strcmp(q, "push_middle") == 0){
            if (l.size() < r.size()){
				l.push_back(r.front());
				r.pop_front();
			}
			r.push_front(x);
        }
        else{
            if (x >= l.size()){
				printf("%d\n", r[x - l.size()]);
			}
			else{
				printf("%d\n", l[x]);
			}
        }

        if (r.size() > l.size()){
            l.push_back(r.front());
            r.pop_front();
        }

        if (l.size() > r.size()+1){
            r.push_front(l.back());
            l.pop_back();
        }

    }

    return 0;
}
