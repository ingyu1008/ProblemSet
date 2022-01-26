#include "testlib.h"
#include <iostream>

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    // Precondition 2 <= N <= 14
    // Precondition 2 <= M <= 1000

    int N = std::stoi(argv[1]);
    int M = std::stoi(argv[2]);

    std::cout << N << " " << M << "\n";

    for (int i = 0; i < M; i++)
    {
        std::cout << rnd.next(-1000, 1000);
        if (i != M - 1)
            std::cout << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << rnd.next(1, M);
            if (j != N - 1)
                std::cout << " ";
        }
        std::cout << "\n";
    }

    return 0;
}