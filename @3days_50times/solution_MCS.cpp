#include <iostream>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    int H, M, S;
    H = M = S = 0;

    for(int i = 0, h, m, s; i < N; i++){
        std::cin >> h >> m >> s;
        H += h;
        M += m;
        S += s;
    }

    M += S/60;
    S %= 60;
    H += M/60;
    M %= 60;

    std::cout << H << " " << M << " " << S << "\n";

    return 0;
}