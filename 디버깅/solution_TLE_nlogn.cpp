#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>

std::vector<int> v, psum;
int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, M;

    std::cin >> N >> M;

    v.resize(N + 1);
    psum.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int a;
        std::cin >> a;
        v[a] = 1;
    }

    for (int i = 1; i <= N; ++i) {
        psum[i] = psum[i - 1] + v[i];
    }

    int X, Y;
    std::cin >> X >> Y;

    int ans = 0;

    for (int l = 1; l <= N; ++l) {
        if (psum[N] - psum[l - 1] < Y) break;
        int idx = std::lower_bound(psum.begin() + l, psum.end(), Y + psum[l - 1]) - psum.begin();
        idx = std::max(idx, std::min(N, l + X - 1));
        int sum = psum[idx] - psum[l - 1];
        if (sum >= Y && idx - l + 1 >= X) {
            ans = std::max(ans, psum[N] - sum);
        }
    }
    std::cout << ans << "\n";



    return 0;
}