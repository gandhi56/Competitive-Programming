#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

void show(list<ii> l){
    cout << endl;
    auto it = l.begin();
    while (it != l.end()){
        cout << it->first << ' ' << it->second << endl;
        it++;
    }
    cout << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    int n;
    cin >> n;
    vector<ii> pool;
    while (n--){
        string s;
        cin >> s;
        if (s == "add"){
            int e, g;
            cin >> e >> g;
            pool.push_back({e, g});
        }
        else{
            sort(pool.begin(), pool.end());
            int x;
            cin >> x;

            int g = 0;

            // find the largest y s.t. y <= x
            while (x >= 1 and pool.size() >= 1){
				//for (auto p : pool)	cout << p.first << ", " << p.second << endl;
                //show(pool);
				//int i;
				//for (i = 0; i+1 < pool.size(); ++i){
				//	if (pool[i].first <= x and pool[i+1].first > x){	
				//		break;
				//	}
				//}


				int lo = 0;
				int hi = pool.size()-1;
				while (lo <= hi){
					int mid = (lo + hi) / 2;
					if (pool[mid].first > x){
						hi = mid - 1;
					}
					else{
						break;
					}
				}
				int i = (lo + hi) / 2;
				if (i >= pool.size() or pool[i].first > x){
					break;
				}
				else{
					while (i+1 < pool.size() and pool[i+1].first <= x){
						++i;
					}
					x -= pool[i].first;
					g += pool[i].second;
					pool.erase(pool.begin()+i);
				}

                //cout << "choosing (" << pool[i].first << ", " << pool[i].second << ")" << endl;
				//cout << "x = " << x << endl;
            }
            cout << g << endl;
        }
    }
    return 0;
}
