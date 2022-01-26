#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>

typedef std::vector<int> vec;
typedef std::vector<vec> matrix;

matrix operator+(const matrix& a, const matrix& b) {
    assert(a.size() == b.size());
    assert(a[0].size() == b[0].size());

    matrix c(a.size(), std::vector<int>(a[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}

matrix operator*(const matrix& a, const matrix& b) {
    assert(a[0].size() == b.size());

    matrix c(a.size(), std::vector<int>(b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

int operator*(const vec& a, const vec& b) {
    assert(a.size() == b.size());

    int c = 0;
    for (int i = 0; i < a.size(); i++) {
        c += a[i] * b[i];
    }
    return c;
}

matrix transpose(const matrix& a) {
    matrix b(a[0].size(), std::vector<int>(a.size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            b[j][i] = a[i][j];
        }
    }
    return b;
}

bool operator==(const matrix& a, const matrix& b) {
    if (a.size() != b.size()) return false;
    if (a[0].size() != b[0].size()) return false;

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            if (a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

matrix randomNbyone(int n) {
    matrix a(n, std::vector<int>(1));
    for (int i = 0; i < n; i++) {
        a[i][0] = rand() % 100;
    }
    return a;
}

int countOK[6] = { 0, 0, 0, 0, 0, 0 }; // AB=C, AC = B, BA = C, BC = A, CA = B, CB = A

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    assert(N >= 1 && N <= 3000);

    matrix A, B, C, AT, BT, CT;
    A.resize(N);
    B.resize(N);
    C.resize(N);

    for (int i = 0; i < N; i++) {
        A[i].resize(N);
        for (int j = 0; j < N; j++) {
            std::cin >> A[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        B[i].resize(N);
        for (int j = 0; j < N; j++) {
            std::cin >> B[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        C[i].resize(N);
        for (int j = 0; j < N; j++) {
            std::cin >> C[i][j];
        }
    }
    AT = transpose(A);
    BT = transpose(B);
    CT = transpose(C);

    int num_iter = 1e4;

    // O(KN) = 10^4 * 1000 = 10^7 * Constant
    for (int i = 0; i < num_iter; i++) {
        int x = rand() % N;
        int y = rand() % N;

        if (A[x] * BT[y] == C[x][y]) {
            countOK[0]++;
        }
        if (A[x] * CT[y] == B[x][y]) {
            countOK[1]++;
        }
        if (B[x] * AT[y] == C[x][y]) {
            countOK[2]++;
        }
        if (B[x] * CT[y] == A[x][y]) {
            countOK[3]++;
        }
        if (C[x] * AT[y] == B[x][y]) {
            countOK[4]++;
        }
        if (C[x] * BT[y] == A[x][y]) {
            countOK[5]++;
        }
    }

    int A_value = 0, B_value = 0, C_value = 0;
    if (countOK[0] == num_iter) {
        A_value |= 1;
        B_value |= 2;
        C_value |= 4;
    }
    if (countOK[1] == num_iter) {
        A_value |= 1;
        C_value |= 2;
        B_value |= 4;
    }
    if (countOK[2] == num_iter) {
        A_value |= 2;
        B_value |= 1;
        C_value |= 4;
    }
    if (countOK[3] == num_iter) {
        A_value |= 4;
        B_value |= 1;
        C_value |= 2;
    }
    if (countOK[4] == num_iter) {
        A_value |= 2;
        B_value |= 4;
        C_value |= 1;
    }
    if (countOK[5] == num_iter) {
        A_value |= 4;
        B_value |= 2;
        C_value |= 1;
    }

    std::cout << A_value << "\n" << B_value << "\n" << C_value << "\n";

    return 0;
}