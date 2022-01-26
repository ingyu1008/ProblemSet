#include "testlib.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>

typedef std::pair<int, char> input;

int L, N, T;
std::vector<input> inputs;

void print();

bool validate() {
    if (L < 5 || L > 1000) return false;
    if (N < 1 || N > 100) return false;
    if (T < 1 || T > 1000) return false;
    for (const auto& p : inputs) {
        if (p.first < 1 || p.first >= L) return false;
        if (p.second != 'L' && p.second != 'R') return false;
    }
    return true;
}

void usage(char* argv[]) {
    std::cout << "Usage: " << argv[0] << " [-l <L>] [-n <N>] [-t <T>] [<Seed>]\n";
}

void generateInputs() {
    std::vector<int> s = rnd.distinct(N, (L-1) / 2);
    int offset = rnd.next(1, 2);
    for (auto& x : s)
        inputs.push_back(input(2 * x + offset, rnd.next(0, 1) ? 'L' : 'R'));
}

void initialize(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    L = rnd.next(5, 1000);
    N = rnd.next(2, std::min(L / 2, 100));
    T = rnd.next(1, 1000);

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-l") == 0) {
            L = atoi(argv[++i]);
        } else if (std::strcmp(argv[i], "-n") == 0) {
            N = atoi(argv[++i]);
        } else if (std::strcmp(argv[i], "-t") == 0) {
            T = atoi(argv[++i]);
        }
    }

    if (N > std::min(L / 2, 100)) {
        N = rnd.next(2, std::min(L / 2, 100));
    }

    generateInputs();

    if (!validate()) {
        usage(argv);
        exit(1);
    }
}

void print() {
    std::cout << L << " " << N << " " << T << std::endl;
    for (const auto& p : inputs) {
        std::cout << p.first << " " << p.second << std::endl;
    }
}

int main(int argc, char* argv[])
{
    initialize(argc, argv);
    print();
    return 0;
}