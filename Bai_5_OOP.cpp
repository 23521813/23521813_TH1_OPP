/**
 *    author:  longvu
 *    created: 09/29/24 16:41:16
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

int memo[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool ktnamnhuan(int nam) { // Hàm kiểm tra năm nhuận (Truyền vào năm).
	return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int ngaythu(int &ngay, int &thang, int &nam) { // Hàm tìm ngày thứ mấy trong năm(Truyền vào ngày, tháng, năm).
    if (ktnamnhuan(nam)) {
        ngayTrongThang[1] = 29;
    }
    int d = ngay;
    for (int i = 0; i < thang - 1; i++) {
        d += ngayTrongThang[i];
    }
    ngayTrongThang[1] = 28;
    return d;
}

void ngaytiep(int &ngay, int &thang, int &nam) { // Hàm tìm ngày tiếp theo của ngày nhập vào(Truyền vào ngày, tháng, năm).
	if (ktnamnhuan(nam)) {
		memo[1] = 29;
	}
	ngay++;
	if (ngay > memo[thang - 1]) {
		ngay = 1;
		thang++;
		if (thang > 12) {
			thang = 1;
			nam++;
		}
	}
	memo[1] = 28;
}

void ngaytruoc(int &ngay, int &thang, int &nam) { // Hàm tìm ngày trước của ngày nhập vào(Truyền vào ngày, tháng, năm).
	if (ktnamnhuan(nam)) {
		memo[1] = 29;
	}
	ngay--;
	if (ngay < 1) {
		thang--;
		if (thang < 1) {
			thang = 12;
			nam--;
		}
		ngay = memo[thang - 1];
	}
	memo[1] = 28;
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ngay, thang, nam;
	cin >> ngay >> thang  >> nam;
	int x = ngay, y = thang, z = nam;
	auto Print = [&]() { // In kết quả
		cout << x << "/" << y << "/" << z << '\n';
		return 0;
	};
	// Tìm ngày kế tiếp
	ngaytiep(x, y, z);
	Print();

	// Tìm ngày trước đó
	x = ngay, y = thang, z = nam;
	ngaytruoc(x, y, z);
	Print();

	// Tính ngày thứ bao nhiêu trong năm
	cout << ngaythu(ngay, thang, nam) << '\n';
	return 0;
}
