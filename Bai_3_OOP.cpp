/**
 *    author:  longvu
 *    created: 09/29/24 15:34:07
**/
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
const int INF = numeric_limits<int>::max();
const int nax = (int)(100001);
const int mod = 1e9 + 7;

template<class X, class Y>
bool maximize(X& x, const Y y) {
    if (y > x) {x = y; return true;}
    return false;
}
template<class X, class Y>
bool minimize(X& x, const Y y) {
    if (y < x) {x = y; return true;}
    return false;
}

struct fac { // Phân số
    int p, q;
};

fac tong(fac a, fac b) {
    return {a.p * b.q + b.p * a.q, a.q * b.q};
}

fac hieu(fac a, fac b) {
    return {a.p * b.q - b.p * a.q, a.q * b.q};
}

fac tich(fac a, fac b) {
    return {a.p * b.p, a.q * b.q};
}

fac thuong(fac a, fac b) {
    return {a.p * b.q, a.q * b.p};
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fac a, b;
    cin >> a.p >> a.q >> b.p >> b.q; // Nhập 2 phân số
    fac anstong = tong(a, b)
                  , anshieu = hieu(a, b)
                              , anstich = tich(a, b)
                                          , ansthuong = thuong(a, b);
    cout << anstong.p << "/" << anstong.q << '\n'; // Tổng 2 phân số.
    cout << anshieu.p << "/" << anshieu.q << '\n'; // Hiệu 2 phân số.
    cout << anstich.p << "/" << anstich.q << '\n'; // Tích 2 phân số.
    cout << ansthuong.p << "/" << ansthuong.q << '\n'; // Thương 2 phân số.
    return 0;
}
