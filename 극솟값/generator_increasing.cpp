#include "testlib.h"
#include <iostream>

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    int N = 1e9;
    int M = 1;
    std::cout << N << " " << M << "\n";

    for (int i = 0; i <= M; i++)
    {
        std::cout << rnd.next(1, 100000); //기울기 양수인 일차함수 -> 항상 증가

        if (i < M)
        {
            std::cout << " ";
        }
    }
    std::cout << "\n";
}