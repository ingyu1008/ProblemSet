#include <iostream>
#include <vector>
#include <algorithm>

int dp[200][20000]; // dp[i][j] = i번자리까지 봤을때 다음 N개의 비트마스킹상태가 j일때 최댓값
int val[200];
int A[1000];

int N, M;
int solve(int now, int bitmask)
{
    if (dp[now][bitmask] >= 0)
        return dp[now][bitmask];
    if (now == N * N)
        return 0;
    int mx = 0;
    if (bitmask & 1)
        mx = solve(now + 1, bitmask >> 1);
    else
    {
        if ((now % N) != N - 1 && (bitmask & 2) == 0)
            mx = std::max(A[(val[now] + val[now + 1]) % M] + solve(now + 2, bitmask >> 2), mx);
        if (now + N < N * N)
            mx = std::max(A[(val[now] + val[now + N]) % M] + solve(now + 1, (bitmask >> 1) | (1 << (N - 1))), mx);
    }
    return dp[now][bitmask] = mx;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::cin >> N >> M;

    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 20000; j++)
        {
            dp[i][j] = -1;
        }
    }

    for (int i = 0; i < M; i++)
    {
        std::cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> val[i * N + j];
        }
    }

    std::cout << solve(0, 0);

    return 0;
}