#include "testlib.h"
#include <iostream>
#include <algorithm>

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    // Precondition 1 <= N <= 100000

    int N = std::stoi(argv[1]);
    std::cout << N << "\n";

    std::vector<int> w;
    w.push_back(0);
    w.push_back(1);
    for (int i = 2; i <= N; i++)
    {
        std::cout << w[i/2] << " " << i << "\n";
        w.push_back(i);
    }

    return 0;
}