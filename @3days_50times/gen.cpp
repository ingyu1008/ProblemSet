#include "testlib.h"
#include <iostream>

typedef long long ll;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    /*
     * argv[1] = N
     */

    int N = std::stoi(argv[1]);
    
    std::cout << N << "\n";

    while(N--){
        std::cout << rnd.next(0, 23) << " ";
        std::cout << rnd.next(0, 59) << " ";
        std::cout << rnd.next(0, 59) << "\n";
    }
}