#include "testlib.h"
#include <iostream>

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    int N = 100000;
    int Q = 100000;

    // Precondition: 1 <= min <= max <= 1e9
    int minAi = 1;
    int maxAi = 1000000000;

    std::cout << N << " " << Q << "\n";

    for (int i = 0; i < N; i++)
    {
        std::cout << rnd.next(minAi, maxAi);
        if (i != N - 1)
            std::cout << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < 50000; i++)
    {
        int q = 1;
        int l = 1;
        int r = N;
        std::cout << q << " " << l << " " << r << "\n";
    }
    for (int i = 0; i < 49999; i++)
    {
        int q = 2;
        int x = rnd.next(1, N);
        std::cout << q << " " << x << "\n";
    }

    std::cout << "2 99999\n";

    return 0;
}