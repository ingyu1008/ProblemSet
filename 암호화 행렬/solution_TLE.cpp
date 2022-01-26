#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>

typedef std::vector<std::vector<int>> matrix;

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

    matrix A, B, C;
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

    int A_value = 0, B_value = 0, C_value = 0;
    if(A*B == C){
        A_value |= 1;
        B_value |= 2;
        C_value |= 4;
    }
    if(A*C == B){
        A_value |= 1;
        C_value |= 2;
        B_value |= 4;
    }
    if(B*A == C){
        A_value |= 2;
        B_value |= 1;
        C_value |= 4;
    }
    if(B*C == A){
        A_value |= 4;
        B_value |= 1;
        C_value |= 2;
    }
    if(C*A == B){
        A_value |= 2;
        B_value |= 4;
        C_value |= 1;
    }
    if(C*B == A){
        A_value |= 4;
        B_value |= 2;
        C_value |= 1;
    }

    std::cout << A_value << "\n" << B_value << "\n" << C_value << "\n";

    return 0;
}