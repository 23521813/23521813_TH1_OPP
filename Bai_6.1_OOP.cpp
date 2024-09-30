/**
 *    author:  longvu
 *    created: 01/02/22 13:03:09
**/
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
const int INF = numeric_limits<int>::max();
const int nax = (int)(1000001);
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

const int nMod = 1;
const int base = 311;

vector<int> Mod = {(int)(1234567891), (int)(1e9 + 9)};

int expo(int a, int b, int mod) { // Tính a mũ b(Truyền vào 2 số a, b và số mod).
    if (!b) {
        return 1;
    }
    int tmp = expo(a, b >> 1, mod);
    if (b & 1) {
        return (tmp * tmp % mod) * (a % mod) % mod;
    }
    return (tmp * tmp % mod);
}

int pw[nax][nMod], inv[nax][nMod];
void precal() { // Chuẩn bị mã hash
    for (int j = 0; j < nMod; ++j) {
        pw[0][j] = 1;
    }
    for (int i = 1; i < nax; ++i) {
        for (int j = 0; j < nMod; ++j) {
            pw[i][j] = (base *  pw[i - 1][j]) % Mod[j];
            inv[i][j] = expo(pw[i][j], Mod[j] - 2, Mod[j]);
        }
    }
}

void build(int h[][nMod], int n, int a[]) { // Xây dựng mã hash(Truyền vào dãy cần xây dựng).
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < nMod; ++j) {
            h[i][j] = (h[i - 1][j] + a[i] * pw[i][j]) % Mod[j]; 
        }
    }
}

array<int, nMod> get(int h[][nMod], int l, int r) {  // Lấy mã hash của 1 đoạn con(Truyền vào mã hash của dãy cần lấy mã hash, 2 tham số l, r là đầu trái và đầu phải).
    array<int, nMod> res;
    for (int j = 0; j < nMod; ++j) {
        res[j] = (h[r][j] - h[l - 1][j] + Mod[j]) * inv[l][j] % Mod[j];
    }
    return res;
}

int is_equal(array<int, nMod> a, array<int, nMod> b) { // Kiểm tra 2 mã hash có bằng nhau hay không(Truyền vào 2 mã hash cần kiểm tra).
    for (int j = 0; j < nMod; ++j) {
        if (a[j] != b[j]) {
            return false;
        }
    }
    return true;
}

int h1[nax][nMod], h2[nax][nMod], A[nax], B[nax];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    precal();
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
    	cin >> A[i];
    }
    for (int i = 1; i <= m; ++i) {
    	cin >> B[i];
    }
    build(h1, n, A);
    build(h2, m, B);
    for (int i = 1; i + n - 1 <= m; ++i) {
        if (is_equal(get(h2, i, i + n - 1), get(h1, 1, n))) {
            cout << i << " ";
        }
    }
    return 0;
}
