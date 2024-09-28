#include<bits/stdc++.h>

using namespace std;

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
}
