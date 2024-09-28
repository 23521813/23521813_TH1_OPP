/**
 *    author:  longvu
 *    created: 09/29/24 00:30:46
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

struct fac { // Phan so
	int p, q;
	bool operator < (const fac& z) const { // So sánh 2 phân số.
		return p * z.q < q * z.p;
	}
};

fac f[21];
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i <= 2; ++i) { // Nhập vào 2 phân số.
		cin >> f[i].p >> f[i].q;
	}
	fac ansmx = {0, 1};
	for (int i = 1; i <= 2; ++i) { // tìm phân số lớn nhát.
		ansmx = max(ansmx, f[i]);
	}
	cout << ansmx.p << "/" << ansmx.q << '\n'; // Xuất kết quả.
	return 0;
}
