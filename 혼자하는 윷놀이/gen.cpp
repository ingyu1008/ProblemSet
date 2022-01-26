#include "testlib.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>

std::vector<std::string> input;

int yut2int(const std::string &s){
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        cnt += (s[i] == '0') ? 1 : 0;
    }

    switch(cnt){
        case 0: return 4;
        case 1: return 1;
        case 2: return 2;
        case 3: return 3;
        default: return 5;
    }
}

bool validate() {
    // No validation needed
    return true;
}

void usage() {
    std::cout << "Usage: gen [<Seed>]\n";
}

void initialize(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int cnt = 10;
    for(int i = 0; i < cnt; i++){
        std::string s;
        for(int j = 0; j < 4; j++){
            s += std::to_string(rnd.next(0, 1));
        }
        input.push_back(s);
        if(yut2int(s) >= 4){
            cnt++;
        }
    }

    if (!validate()) {
        usage();
        exit(1);
    }
}

void print() {
    for(const auto &s : input){
        std::cout << s << "\n";
    }
}

int main(int argc, char* argv[])
{
    initialize(argc, argv);
    print();
    return 0;
}