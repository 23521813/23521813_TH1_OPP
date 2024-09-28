/**
 *    author:  longvu
 *    created: 09/28/24 23:14:50
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

int gcd(int a, int b) {
	return (!b ? a : gcd(b, a % b));
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b; // nhập phân số
    int _gcd = gcd(a, b); // tính ước chung lớn nhất
    cout << a / _gcd << "/" << b / _gcd << '\n'; // xuất kết quả
    return 0;
}