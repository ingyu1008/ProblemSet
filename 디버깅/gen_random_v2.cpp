#include "testlib.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>

int N = -1, M = 0, X = -1, Y = -1;
std::vector<int> v;

void usage() {
    std::cout << "Usage: gen_random_v2 <N> <X> [-m <M>] [-y <Y>] [<Seed>]\n";
}

bool validate() {
    return 1 <= N && N <= 2 * 1e7 && 0 <= M && M <= std::min(N, 500000) && 0 <= X && X <= N && 0 <= Y && Y <= M && v.size() == M;
}

void initialize(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    N = std::stoi(argv[1]);
    X = std::stoi(argv[2]);

    M = rnd.next(0, std::min(N, 500000));
    Y = rnd.next(0, M);

    for (int i = 3; i < argc; i++) {
        if (strcmp(argv[i], "-m") == 0) {
            M = std::stoi(argv[i + 1]);
            i++;
        } else if (strcmp(argv[i], "-y") == 0) {
            Y = std::stoi(argv[i + 1]);
            i++;
        } else {
            std::cout << "Unknown option: " << argv[i] << "\n";
            usage();
            exit(0);
        }
    }

    v = rnd.distinct(M, 1, N);
    std::sort(v.begin(), v.end());

    if (N < 0 || X < 0 || !validate()) {
        usage();
        exit(0);
    }
}

int main(int argc, char* argv[])
{
    initialize(argc, argv);

    std::cout << N << " " << M << "\n";

    for (int i = 0; i < M; i++)
    {
        std::cout << v[i];
        if (i < M - 1) std::cout << " ";
    }
    std::cout << "\n";

    std::cout << X << " " << Y << "\n";


    return 0;
}