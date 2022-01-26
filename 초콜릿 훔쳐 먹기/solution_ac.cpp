#include <iostream>
#include <cmath>

typedef long long ll;

ll solve(ll N, ll M, ll K, ll diff_old) {
    ll x = N * M - 1;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i > 0) continue;
        ll nextN = i;
        ll nextM = x / i;

        ll diff = nextN - nextM;
        if (std::abs(diff - diff_old) > K) continue;
        return nextN;
    }
    return -1;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    ll N, M, K;
    std::cin >> N >> M >> K;

    ll x = N * M;

    // Assure that N > M
    if (N < M) std::swap(N, M);

    ll diff_old = N - M;

    ll result = 0;

    ll nextN = solve(N, M, K, diff_old);
    while (nextN > 0 || result < x) {
        result++;
        N = nextN;
        M = (x - result) / N;
        diff_old = N - M;
        nextN = solve(N, M, K, diff_old);
    }

    std::cout << result << "\n";

    return 0;
}