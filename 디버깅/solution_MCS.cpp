#include <iostream>
#include <vector>
#include <algorithm>

    std::vector<int> v, psum;

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, M;

    std::cin >> N >> M;

    v.resize(N+1);
    psum.resize(N+1);

    for(int i = 0; i < M; i++){
        int a;
        std::cin >> a;
        v[a] = 1;
    }

    for (int i = 1; i <= N; ++i) {
        psum[i] = psum[i - 1] + v[i];
    }

    int X, Y;
    std::cin >> X >> Y;

    int l = 1, r = X + 1; // [l, r)

    int ans = 0;

    while (r <= N + 1) {
        int sum = psum[r - 1] - psum[l - 1];
        while (sum >= Y && r - l >= X) {
            ans = std::max(ans, psum[N] - sum);
            l++;
            sum = psum[r - 1] - psum[l - 1];
        }

        if (l + X > N + 1 || psum[N] - psum[l - 1] < Y) break;

        while (r <= N && (r - l < X || sum < Y)) {
            ++r;
            sum = psum[r - 1] - psum[l - 1];
        }
    }

    std::cout << ans << "\n";


    return 0;
}