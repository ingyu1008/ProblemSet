#include "testlib.h"
#include <iostream>

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    int T = 5000;
    std::cout << T << "\n";
    for (int t = 0; t < T; t++)
    {
        int N = 2e6;
        int M = 1;
        std::cout << N << " " << M << "\n";

        for (int i = 0; i <= M; i++)
        {
            std::cout << rnd.next(-100000, -1);

            if (i < M)
            {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}