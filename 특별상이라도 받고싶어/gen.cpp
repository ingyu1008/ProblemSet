#include "testlib.h"
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <vector>

typedef long long ll;

int main(int argc, char* argv[])
{
    if (argc < 4)
    {
        std::cerr << "Usage: " << argv[0] << " <N> <mn> <mx>\n";
        return -1;
    }

    registerGen(argc, argv, 1);

    /*
     * argv[1] = N
     * argv[2] = mn
     * argv[3] = mx
     */

     //[IMPORTANT] mx-mn <= N^2
     //[IMPORTANT] N <= 1024, N = 2^k

    int N = std::stoi(argv[1]);
    int mn = std::stoi(argv[2]);
    int mx = std::stoi(argv[3]);

    assert(__builtin_popcount(N) == 1);
    assert(mn <= mx);
    assert(mx - mn + 1 >= N * N);
    assert(N <= 1024);

    auto v = rnd.distinct(N * N, mn, mx);

    std::cout << N << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << v[i * N + j];
            if (j != N - 1) std::cout << " ";
        }
        std::cout << std::endl;
    }
}