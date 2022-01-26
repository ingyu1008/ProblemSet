#include "testlib.h"
#include <iostream>

typedef long long ll;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    /*
     * argv[1] = T
     * argv[2] = minX
     * argv[3] = maxX
     * argv[4] = minY
     * argv[5] = maxY
     * argv[6] = minH
     * argv[7] = maxH
     * argv[8] = minD
     * argv[9] = maxD
     */

    int T = std::stoi(argv[1]);
    std::cout << T << "\n";

    int minX = std::stoi(argv[2]);
    int maxX = std::stoi(argv[3]);
    int minY = std::stoi(argv[4]);
    int maxY = std::stoi(argv[5]);
    int minH = std::stoi(argv[6]);
    int maxH = std::stoi(argv[7]);
    int minD = std::stoi(argv[8]);
    int maxD = std::stoi(argv[9]);

    while (T--)
    {
        int x = rnd.next(minX, maxX);
        int y = rnd.next(minY, maxY);
        int h = rnd.next(minH, maxH);
        int d = rnd.next(std::max(x + 1, minD), maxD);
        std::cout << x << " " << y << " " << h << " " << d << "\n";
    }
}