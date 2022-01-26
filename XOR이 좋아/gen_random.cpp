#include "testlib.h"
#include <iostream>

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    int N = std::stoi(argv[1]);

    std::cout << N << "\n";

    for (int i = 0; i < N; i++)
    {
        std::cout << rnd.next(0, 1000);
        if (i != N - 1)
            std::cout << " ";
    }
    std::cout << "\n";
    
    return 0;
}