#include <iostream>
#include <vector>
#include <complex>
#include <valarray>
#include <cmath>
using namespace std;

typedef complex<double> cplex;

void nextPower(long long& n){
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
}

void fft(valarray<cplex>& x){
    long long s = x.size();
    if (s <= 1)
        return;
    
    valarray<cplex> even = x[slice(0, s/2, 2)];
    valarray<cplex> odd = x[slice(1, s/2, 2)];

    fft(even);
    fft(odd);

    for (long long i = 0; i < s / 2; ++i){
        cplex t = polar(1.0, -2.0 * M_PI * i / s) * odd[i];
        x[i] = even[i] + t;
        x[i+s/2] = even[i] - t;
    }
}

void ifft(valarray<cplex>& x){
    x = x.apply(conj);
    fft(x);
    x = x.apply(conj);
    x /= x.size();
}

int main(){
    string s;
    cin >> s;

    long long size = s.size();
    size++;
    nextPower(size);
    size++;
    nextPower(size);

    valarray<cplex> v1(size);
    valarray<cplex> v2(size);

    for (long long i =0 ; i < s.size(); ++i){
        v1[i] = (s[i] - 'A') ^ 1;
        v2[size - i - 1] = (s[i] - 'A');
    }


    fft(v1);
    fft(v2);

    for (long long i = 0; i < size; ++i){
        v1[i] *= v2[i];
    }

    ifft(v1);

    for (long long i = 0; i < s.size()-1; ++i){
        cout << (long long)(v1[i].real()+.25) << endl;
    }

    return 0;
}