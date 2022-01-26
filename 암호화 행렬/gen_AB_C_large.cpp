#include "testlib.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>

typedef std::vector<std::vector<int>> matrix;

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

matrix randomNbyN(int n) {
    matrix a(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rnd.next(-10000000, 10000000);
        }
    }
    return a;
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    int N = std::stoi(argv[1]);

    std::cout << N << "\n";
    matrix X = randomNbyN(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << X[i][j];
            if (j < N - 1) std::cout << " ";
        }
        std::cout << "\n";
    }
    matrix Y = randomNbyN(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << Y[i][j];
            if (j < N - 1) std::cout << " ";
        }
        std::cout << "\n";
    }

    matrix Z = X * Y;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << Z[i][j];
            if (j < N - 1) std::cout << " ";
        }
        std::cout << "\n";
    }


    return 0;
}