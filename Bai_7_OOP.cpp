/**
 *    author:  longvu
 *    created: 09/29/24 18:50:50
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

struct ChuyenBay {
    string machuyenbay;
    string ngaybay; // Định dạng: DD/MM/YYYY
    string giobay;  // Định dạng: HH:MM (24 gio)
    string noiDi;
    string noiDen;
};

//Hàm kiểm tra mã chuyến bay (toi da 5 ky tu, khong chua khoang trang va ky tu dac biet)
bool ktmacb(const string &s) {
    if (s.length() > 5) return false;
    for (char c : s) {
        if (!isalnum(c)) return false;
    }
    return true;
}

// Hàm kiểm tra năm nhuận(Truyền vào năm)
bool ktnamnhuan(int nam) {
	return (nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0;
}

// Hàm kiểm tra ngày bay hợp lệ(Truyền vào ngày)
bool ngayktngaycb(const string &ngay) {
    if (ngay.length() != 10 || ngay[2] != '/' || ngay[5] != '/') return false;
    int Ngay = stoi(ngay.substr(0, 2));
    int Thang = stoi(ngay.substr(3, 2));
    int Nam = stoi(ngay.substr(6, 4));
    if (Thang < 1 || Thang > 12 || Ngay < 1 || Ngay > 31) return false;
    int ngayTrongThang[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (ktnamnhuan(Nam)) {
        ngayTrongThang[1] = 29;
    }
    return Ngay <= ngayTrongThang[Thang - 1];
}

// Hàm kiểm tra giừ bay hợp lệ(Truyền vào giờ)
bool ktgiobay(const string &gio) {
    if (gio.length() != 5 || gio[2] != ':') return false;
    int Gio = stoi(gio.substr(0, 2));
    int Phut = stoi(gio.substr(3, 2));
    return Gio >= 0 && Gio <= 23 && Phut >= 0 && Phut <= 59;
}

// Hàm kiem tra địa diểm(Truyền vào địa điểm)
bool ktdiadiem(const string &s) {
    if (s.length() > 20) return false;
    for (char c : s) {
        if (!isalpha(c) && c != ' ') return false;
    }
    return true;
}

// Hàm nhập
ChuyenBay input() {
    ChuyenBay cb;
    do {
        cout << "Nhap ma chuyen bay (toi da 5 ky tu, khong chua khoang trang/ky tu dac biet): ";
        cin >> cb.machuyenbay;
    } while (!ktmacb(cb.machuyenbay));
    do {
        cout << "Nhap ngay bay (Dinh dang DD/MM/YYYY): ";
        cin >> cb.ngaybay;
    } while (!ngayktngaycb(cb.ngaybay));
    do {
        cout << "Nhap gio bay (Dinh dang HH:MM, 24 gio): ";
        cin >> cb.giobay;
    } while (!ktgiobay(cb.giobay));
    cin.ignore();
    do {
        cout << "Nhap noi di (toi da 20 ky tu, khong chua so hoac ky tu dac biet): ";
        getline(cin, cb.noiDi);
    } while (!ktdiadiem(cb.noiDi));
    do {
        cout << "Nhap noi den (toi da 20 ky tu, tuong tu noi di): ";
        getline(cin, cb.noiDen);
    } while (!ktdiadiem(cb.noiDen));
    return cb;
}

// Ham hien thi thong tin chuyen bay
void hienThiChuyenBay(const ChuyenBay &cb) {
    cout << "Ma chuyen bay: " << cb.machuyenbay << ", Ngay bay: " << cb.ngaybay
         << ", Gio bay: " << cb.giobay << ", Noi di: " << cb.noiDi
         << ", Noi den: " << cb.noiDen << endl;
}

// Ham so sanh ngay va gio khoi hanh de sap xep
bool soSanhThoiGian(const ChuyenBay &a, const ChuyenBay &b) {
    if (a.ngaybay != b.ngaybay) return a.ngaybay < b.ngaybay;
    return a.giobay < b.giobay;
}

// Ham tim kiem chuyen bay theo ma chuyen bay
void timKiemTheomachuyenbay(const vector<ChuyenBay> &danhsach, const string &macb) {
    for (const auto &cb : danhsach) {
        if (cb.machuyenbay == macb) {
            hienThiChuyenBay(cb);
            return;
        }
    }
    cout << "Khong tim thay chuyen bay voi ma '" << macb << "'.\n";
}

// Ham tim kiem chuyen bay theo noi di hoac noi den
void timKiemTheoNoi(const vector<ChuyenBay> &danhsach, const string &noi, bool timNoiDi) {
    for (const auto &cb : danhsach) {
        if ((timNoiDi && cb.noiDi == noi) || (!timNoiDi && cb.noiDen == noi)) {
            hienThiChuyenBay(cb);
        }
    }
}

// Ham liet ke tat ca cac chuyen bay khoi hanh tu noi di trong mot ngay cu the
void hienThiChuyenBayTheoNoiDiVaNgay(const vector<ChuyenBay> &danhsach, const string &noiDi, const string &ngay) {
    bool timThay = false;
    for (const auto &cb : danhsach) {
        if (cb.noiDi == noiDi && cb.ngaybay == ngay) {
            hienThiChuyenBay(cb);
            timThay = true;
        }
    }
    if (!timThay) {
        cout << "Khong co chuyen bay nao khoi hanh tu '" << noiDi << "' vao ngay '" << ngay << "'.\n";
    }
}

// Ham dem so chuyen bay tu noi di den noi den nhat dinh
int demSoChuyenBay(const vector<ChuyenBay> &danhsach, const string &noiDi, const string &noiDen) {
    int dem = 0;
    for (const auto &cb : danhsach) {
        if (cb.noiDi == noiDi && cb.noiDen == noiDen) {
            dem++;
        }
    }
    return dem;
}

int32_t main() {
    cout << "Nhap so luong chuyen bay: ";
    int n;
    cin >> n;
    vector<ChuyenBay> danhsachChuyenBay(n);
    // Nhap thong tin cho tung chuyen bay
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin cho chuyen bay thu " << i + 1 << ":\n";
        danhsachChuyenBay[i] = input();
    }
    // Tim kiem chuyen bay theo ma
    string maCB;
    cout << "\nNhap ma chuyen bay can tim: ";
    cin >> maCB;
    timKiemTheomachuyenbay(danhsachChuyenBay, maCB);
    // Sap xep danh sach chuyen bay theo ngay gio khoi hanh
    sort(danhsachChuyenBay.begin(), danhsachChuyenBay.end(), soSanhThoiGian);
    cout << "\nDanh sach chuyen bay da sap xep theo ngay gio khoi hanh:\n";
    for (const auto &cb : danhsachChuyenBay) {
        hienThiChuyenBay(cb);
    }
    // Liet ke tat ca cac chuyen bay khoi hanh tu noi di trong mot ngay
    string noiDi, ngay;
    cout << "\nNhap noi di va ngay de hien thi chuyen bay:\n";
    cout << "Noi di: ";
    cin.ignore();
    getline(cin, noiDi);
    cout << "Ngay bay (Dinh dang DD/MM/YYYY): ";
    cin >> ngay;
    hienThiChuyenBayTheoNoiDiVaNgay(danhsachChuyenBay, noiDi, ngay);
    // Dem so chuyen bay tu noi di den noi den
    string noiDen;
    cout << "\nNhap noi di va noi den de dem so chuyen bay:\n";
    cout << "Noi di: ";
    cin.ignore();
    getline(cin, noiDi);
    cout << "Noi den: ";
    getline(cin, noiDen);
    int soChuyenBay = demSoChuyenBay(danhsachChuyenBay, noiDi, noiDen);
    cout << "So luong chuyen bay tu '" << noiDi << "' den '" << noiDen << "': " << soChuyenBay << endl;

    return 0;
}
