#include "testlib.h"
#include <iostream>

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    int N = 3;
    int M = 1;
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
