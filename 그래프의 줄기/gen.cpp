#include "testlib.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>

typedef std::pair<int, int> edge;

int N;
std::string mode = "default";
std::vector<edge> graph;

void print();

bool validate() {
    if (N < 2 || N > 100000) return false;
    return true;
}

void usage(char* argv[]) {
    std::cout << "Usage: " << argv[0] << " [-n <N>] [--mode <mode>] [<Seed>]\n";
}

void generateTree(std::string mode) {
    std::vector<int> seed;
    std::vector<int> v;
    for (int i = 0; i < N; i++) {
        seed.push_back(i);
    }

    shuffle(seed.begin(), seed.end());

    if (mode == "straight") {
        for (int i = 0; i < N - 1; i++) {
            graph.push_back(edge(seed[i], seed[i + 1]));
        }
    } else if (mode == "star") {
        for (int i = 1; i < N; i++) {
            graph.push_back(edge(seed[0], seed[i]));
        }
    } else if (mode == "triangle") {
        if (seed.size() < 3) exit(1);
        graph.push_back(edge(seed[0], seed[1]));
        graph.push_back(edge(seed[0], seed[2]));
        graph.push_back(edge(seed[0], seed[3]));
        for (int i = 4; i < N; i++) {
            graph.push_back(edge(seed[i - 3], seed[i]));
        }
    } else if (mode == "four") {
        if (seed.size() < 4) exit(1);
        graph.push_back(edge(seed[0], seed[1]));
        graph.push_back(edge(seed[0], seed[2]));
        graph.push_back(edge(seed[1], seed[3]));
        for (int i = 4; i < N; i++) {
            graph.push_back(edge(seed[i - 4], seed[i]));
        }
    } else {
        v.push_back(seed[0]);
        for (int i = 1; i < N; i++) {
            graph.push_back(edge(rnd.any(v), seed[i]));
            v.push_back(seed[i]);
        }
    }
}

void initialize(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    N = rnd.next(2, 100000);

    for (int i = 0; i < argc; i++) {
        if (std::string(argv[i]) == "-n") {
            N = atoi(argv[i + 1]);
            i++;
        } else if (std::string(argv[i]) == "--mode") {
            mode = std::string(argv[i + 1]);
            i++;
        }
    }

    generateTree(mode);

    if (!validate()) {
        usage(argv);
        exit(1);
    }
}

void print() {
    std::cout << N << std::endl;
    for (const auto& e : graph) {
        std::cout << e.first << " " << e.second << std::endl;
    }
}

int main(int argc, char* argv[])
{
    initialize(argc, argv);
    print();
    return 0;
}