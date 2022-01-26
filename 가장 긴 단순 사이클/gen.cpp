#include "testlib.h"
#include <iostream>

typedef long long ll;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    /*
     * argv[1] = T
     * argv[2] = minN
     * argv[3] = maxN
     * argv[4] = minC
     * argv[5] = maxC
     */

    //[IMPORTANT] maxN*T <= 10^5

    int T = std::stoi(argv[1]);
    std::cout << T << "\n";

    int minN = std::stoi(argv[2]);
    int maxN = std::stoi(argv[3]);
    int minC = std::stoi(argv[4]);
    int maxC = std::stoi(argv[5]);

    while (T--)
    {
        int N = rnd.next(minN, maxN);
        std::cout << N << "\n";
        std::vector<int> c(N);
        for (int i = 0; i < N; i++)
        {
            c[i] = rnd.next(minC, maxC);
            std::cout << c[i];
            if (i < N - 1)
                std::cout << " ";
        }
        std::cout << "\n-1";

        for (int i = 1; i < N; i++)
        {
            std::cout << " " << rnd.next(1, c[i - 1]);
        }
        std::cout << "\n-1";

        for (int i = 1; i < N; i++)
        {
            std::cout << " " << rnd.next(1, c[i - 1]);
        }
        std::cout << "\n";
    }
}