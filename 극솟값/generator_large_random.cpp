#include "testlib.h"
#include <iostream>

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    int T = 5000;
    std::cout << T << "\n";
    for (int t = 0; t < T; t++)
    {
        int N = rnd.next(1900000,2000000);
        int M = rnd.next(90,100);
        std::cout << N << " " << M << "\n";

        for (int i = 0; i <= M; i++)
        {
            std::cout << rnd.next(-100000, 100000);

            if (i < M)
            {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}