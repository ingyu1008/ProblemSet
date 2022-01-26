#include "testlib.h"
#include <iostream>

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    // Precondition 1 <= N, Q <= 1e5

    int N = std::stoi(argv[1]);
    int Q = std::stoi(argv[2]);

    // Precondition: 1 <= min <= max <= 1e9
    int minAi = std::stoi(argv[3]);
    int maxAi = std::stoi(argv[4]);

    std::cout << N << " " << Q << "\n";

    for (int i = 0; i < N; i++)
    {
        std::cout << rnd.next(minAi, maxAi);
        if (i != N - 1)
            std::cout << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < Q-1; i++)
    {
        int q = rnd.next(1, 2);
        if (q == 1)
        {
            int l = rnd.next(1, N);
            int r = rnd.next(l, N);
            std::cout << q << " " << l << " " << r << "\n";
        }
        else
        {
            int x = rnd.next(1, N);
            std::cout << q << " " << x << "\n";
        }
    }

    std::cout << "2 1\n";

    return 0;
}