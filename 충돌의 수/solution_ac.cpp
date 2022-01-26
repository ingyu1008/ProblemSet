#include <iostream>
#include <vector>

typedef std::pair<int, char> input;

int L, N, T;
std::vector<input> inputs;

void init(){
    std::cin >> L >> N >> T;
    inputs.resize(N);
    for(int i = 0; i < N; i++){
        std::cin >> inputs[i].first >> inputs[i].second;
    }
}

void simulate(){
    for(auto &p: inputs){
        if(p.second == 'L'){
            p.first = p.first - 1;
        }
        else{
            p.first = p.first + 1;
        }
        if(p.first == 0) p.second = 'R';
        if(p.first == L) p.second = 'L';
    }
}

int countConflict(){
    int ret = 0;
    for(auto &p: inputs){
        for(auto &q: inputs){
            ret += (p.first == q.first && p.second != q.second);
        }
    }
    return ret/2;
}

void solve(){
    int ans = 0;
    for(int i = 0; i < T; i++){
        simulate();
        ans += countConflict();
    }
    std::cout << ans << std::endl;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    
    init();
    solve();

    return 0;
}