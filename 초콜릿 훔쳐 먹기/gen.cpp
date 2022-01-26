#include "testlib.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>

int N = 0, M = 0, K = 0;

bool validate() {
    if (N < 1 || N > 10000) return false;
    if (M < 1 || M > 10000) return false;
    if (K < 1 || K > N * M) return false;
    return true;
}

void usage() {
    std::cout << "Usage: gen <N> <M> [-k <K>] [<Seed>]\n";
}

void initialize(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    if (argc < 3) {
        usage();
        exit(1);
    }

    N = std::stoi(argv[1]);
    M = std::stoi(argv[2]);
    if (argc > 3 && strcmp(argv[3], "-k") == 0) {
        K = std::stoi(argv[4]);
    } else {
        K = rnd.next(1, N * M);
    }

    if (!validate()) {
        usage();
        exit(1);
    }
}

void print() {
    std::cout << N << " " << M << " " << K << "\n";
}

int main(int argc, char* argv[])
{
    initialize(argc, argv);
    print();
    return 0;
}