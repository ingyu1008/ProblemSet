#include <iostream>
#include <map>
#include <bitset>

int N;

struct Comparator {
    bool operator() (const std::bitset<100> &b1, const std::bitset<100> &b2) const {
        return b1.to_ulong() < b2.to_ulong();
    }
};

std::map<std::bitset<100>, int, Comparator> dp[100];
int finish;

int E[20];
int C[20];

int sumC = 0;

int solve(int cur, std::bitset<100> bitmask)
{
    int me = std::max(0, E[cur] - sumC);
    if (bitmask.all() || me == 0)
    {
        return me;
    }

    if (dp[cur][bitmask] != 0)
    {
        return dp[cur][bitmask];
    }

    int m = 0;
    sumC += C[cur];
    std::bitset<100> next = bitmask;

    for (int i = 0; i < 5; i++)
    {
        if (bitmask.test(i) == 0)
        {
            next.set(i);
            m = std::max(m, solve(i, next) + me);
            next.reset(i);
        }
    }

    sumC -= C[cur];
    return dp[cur][bitmask] = m;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    //Brute Force with Bitmask

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        std::cin >> E[i];
    }

    for (int i = 0; i < N; i++)
    {
        std::cin >> C[i];
    }

    int ans = 0;

    std::bitset<100> bitmask;

    for (int i = 0; i < N; i++)
    {
        bitmask.set(i);
        sumC = 0;
        ans = std::max(ans, solve(i, bitmask));
        bitmask.reset(i);
    }

    std::cout << ans << "\n";
    return 0;
}