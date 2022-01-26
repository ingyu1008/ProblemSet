#include <iostream>

int dp[2][2048];

void add(int x, int y)
{
    for (int i = 0; i < 2048; i++)
    {
        if (dp[y ^ 1][i ^ x])
            dp[y][i] = std::max(dp[y ^ 1][i], dp[y ^ 1][i ^ x] + 1);
    }
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    int x;
    std::cin >> x;
    dp[0][x] = 1;

    for (int i = 1; i < N; i++)
    {
        std::cin >> x;
        add(x, i & 1);
    }

    std::cout << dp[(N - 1) & 1][0] << "\n";

    return 0;
}