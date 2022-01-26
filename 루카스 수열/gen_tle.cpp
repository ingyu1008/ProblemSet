#include "testlib.h"
#include <iostream>

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    int M = std::stoi(argv[1]);

    std::cout << M << "\n";

    for (int i = 0; i < M; i++)
    {
        std::cout << rnd.next(-100000, 100000) << " ";
        std::cout << rnd.next(-100000, 100000) << " ";
        std::cout << rnd.next(100000) << "\n";
    }

    return 0;
}