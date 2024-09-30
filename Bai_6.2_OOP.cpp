/**
 *    author:  longvu
 *    created: 09/29/24 17:34:55
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

struct Hocsinh { // Thong tin hoc sinh
	string Hoten;
	double Diemtoan, Diemvan, Diemanh;
};

bool ktsauhople(string s) { // Kiểm tra xâu hợp lệ
	for (int i = 0; i < sz(s); ++i) {
		if (s[i] >= '0' && s[i] <= '9') return false;
	}
	return true;
}

bool ktso(double x) { Kiểm tra số hợp lệ
	return (x >= 0 && x <= 10);
};

Hocsinh Hocs[nax];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	do {
    		cout << "Nhap ho ten hoc sinh thu " << i << ": " << endl;
    		cin.ignore();
    		getline(cin, Hocs[i].Hoten);
    	} while (ktsauhople(Hocs[i].Hoten) == false);
    	do {
			cout << "Nhap diem toan hoc sinh thu " << i << ": " << endl;
			cin >> Hocs[i].Diemtoan;
		} while (ktso(Hocs[i].Diemtoan) == false);
		do {
			cout << "Nhap diem van hoc sinh thu " << i << ": " << endl;
			cin >> Hocs[i].Diemvan;
		} while (ktso(Hocs[i].Diemvan) == false);
		do {
			cout << "Nhap diem anh hoc sinh thu " << i << ": " << endl;
			cin >> Hocs[i].Diemanh;
		} while (ktso(Hocs[i].Diemanh) == false);
    }
    // Tinh diem trung binh
	// Phan loai hoc sinh
	for (int i = 1; i <= n; ++i) {
		int diem = (2 * Hocs[i].Diemtoan + Hocs[i].Diemvan + Hocs[i].Diemanh) / 4;
		cout << "Diem trung binh cua hoc sinh " << Hocs[i].Hoten << " la: " << diem << "\n";
		if (diem >= 9) {
			cout << Hocs[i].Hoten << " xep loai gioi\n";
		} else if (diem >= 8) {
			cout << Hocs[i].Hoten << " xep loai kha\n";
		} else if (diem >= 6.5) {
			cout << Hocs[i].Hoten << " xep loai trung binh\n";
		} else {
			cout << Hocs[i].Hoten << " xep loai yeu\n";
		}
	}
	// Tim hoc xinh co diem trung binh cao nhat
	double maxdiem = -1;
	string hoten = "";
	for (int i = 1; i <= n; ++i) {
		int diem = (2 * Hocs[i].Diemtoan + Hocs[i].Diemvan + Hocs[i].Diemanh) / 4;
		if (maxdiem < diem) {
			maxdiem = diem;
			hoten = Hocs[i].Hoten;
		}
	}
	cout << "Hoc sinh co diem trung binh cao nhat la: " << hoten << " voi diem la: " << maxdiem << '\n';
	// Tim danh sach hoc sinh voi diem toan thap nhat
	double mindiemtoan = 11;
	for (int i = 1; i <= n; ++i) {
		if (mindiemtoan > Hocs[i].Diemtoan) {
			mindiemtoan = Hocs[i].Diemtoan;
		}
	}
	cout << "Danh sach hoc sinh co diem toan thap nhat la: ";
	for (int i = 1; i <= n; ++i) {
		if (mindiemtoan == Hocs[i].Diemtoan) {
			cout << Hocs[i].Hoten << " ";
		}
	}
	cout << '\n';
    return 0;
}
