#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll ub = n/k;
    ll lb = ub-m+1;
    if (lb < 0) lb = 0;
    ll mx = 0;
    //cerr << "n = " << n << ", m = " << m << ", k = " << k << endl;
    //cerr << "lb = " << lb << ", ub = " << ub << ": " << endl;
    for (ll u = lb; u <= ub; ++u) {
        // u = # of groups of size k
        // r = remaining gnomes (r = v*m + q)
        // v = # of evenly split groups
        // q = remaining gnomes of v (q < m)
        // n = u*k + v*m + q
        ll r = n - k*u;
        ll v = r / m;
        ll q = r % m;
        //cerr << "  u = " << u << " : " << n << " = " << u << "*" << k << " + " << v << "*" << m << " + " << q;
        ll dmg = 0;
        // # damage before u groups taken out
        dmg += (u*(u+1)/2)*k + u*r;
        //cout << ", 1st dmg = " << dmg;
        dmg += (m*(m+1)/2)*v + (q*(q+2)/2);
        //cout << ", 2nd dmg = " << dmg;
        //dmg += (v*(v+1)/2)*m + v*q;
        //dmg += (q*(q+1)/2);
        //cout << ", total dmg = " << dmg << endl;
        mx = max(mx, dmg);
    }
    cout << mx << endl;
    return 0;
}
