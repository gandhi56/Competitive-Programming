#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cout << fixed << setprecision(8);
    double c;
    int l;
    cin >> c >> l;

    double sum = 0.0;
    while (l--){
        double w, h;
        cin >> w >> h;
        sum += w*h;
    }

    cout << sum*c << endl;

    return 0;
}