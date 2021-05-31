#include "testlib.h"
#include <iostream>

typedef long long ll;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    /*
     * argv[1] = V
     * argv[2] = E
     * argv[3] = x
     */

    //[IMPORTANT] 1 <= x <= V

    int V = std::stoi(argv[1]);
    int E;
    std::string sparsity = argv[2];

    if (sparsity == "sparse")
    {
        E = rnd.next(1, V - 1);
    }
    else if (sparsity == "normal")
    {
        E = rnd.next(V - 1, V * (V - 1) / 2);
    }
    else if (sparsity == "full")
    {
        E = V * (V - 1) / 2;
    }

    std::cout << V << " " << E << "\n";

    int x = std::stoi(argv[3]);
}