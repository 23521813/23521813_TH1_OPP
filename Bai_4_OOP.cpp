/**
 *    author:  longvu
 *    created: 09/29/24 01:22:22
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

long double Sin(long double x, long double Exp = 0.00001) {
	long double cur = x;
	long double res = cur;
	for (int d = 1;fabs(cur) > Exp; ++d) {
		cur *= - x * x / ((2 * d) * (2 * d + 1));
		res += cur;
	}
	return res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long double x;
	cin >> x; // Nhập số x.
	cout << setprecision(5) << fixed << Sin(x, 0.00001) << '\n'; // In kết quả.
	return 0;
}
