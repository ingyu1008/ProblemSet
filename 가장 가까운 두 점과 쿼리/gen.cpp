#include "testlib.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>

typedef std::pair<int, int> Point;

enum Mode {
    DEFAULT = 0,
};

int N, Q;
int Min, Max;
std::string mode = "default";
std::vector<Point> points;
std::vector<Point> queries;

Mode parseMode(std::string s) {
    if (s == "default") {
        return DEFAULT;
    }
    return DEFAULT;
}

void print();

bool validate() {
    // refer to validator.cpp
    return true;
}

void usage(char* argv[]) {
    std::cout << "Usage: " << argv[0] << " [--n <N>] [--q <Q>] [--min <Min>] [--max <Max>] [--mode <mode>] [<Seed>]\n";
}

void generate(Mode mode) {
    switch (mode) {
    case DEFAULT:
    default:
        for (int i = 0; i < N; i++) {
            points.push_back(Point(rnd.next(Min, Max), rnd.next(Min, Max)));
            queries.push_back(Point(rnd.next(Min, Max), rnd.next(Min, Max)));
        }
        break;
    }
}

void initialize(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    N = rnd.next(1, 100000);
    Q = rnd.next(1, 100000);
    Min = -1e9;
    Max = 1e9;

    for (int i = 0; i < argc; i++) {
        if (std::string(argv[i]) == "--n") {
            N = atoi(argv[i + 1]);
            i++;
        } else if (std::string(argv[i]) == "--q") {
            Q = atoi(argv[i + 1]);
            i++;
        } else if (std::string(argv[i]) == "--mode") {
            mode = std::string(argv[i + 1]);
            i++;
        } else if (std::string(argv[i]) == "--min") {
            Min = atoi(argv[i + 1]);
            i++;
        } else if (std::string(argv[i]) == "--max") {
            Max = atoi(argv[i + 1]);
            i++;
        }
    }

    generate(parseMode(mode));

    if (!validate()) {
        usage(argv);
        exit(1);
    }
}

void print() {
    std::cout << N << std::endl;
    for (const auto& e : points) {
        std::cout << e.first << " " << e.second << std::endl;
    }
    std::cout << Q << std::endl;
    for (const auto& e : queries) {
        std::cout << e.first << " " << e.second << std::endl;
    }
}

int main(int argc, char* argv[])
{
    initialize(argc, argv);
    print();
    return 0;
}