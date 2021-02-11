#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

std::vector<int> coef;

int N, M;
ll mod = 1e9 + 7;

ll f(ll x)
{
    if (x == 0)
        return 2147483647;
    if (x == N + 1)
        return 2147483647;
    ll res = 0;
    ll xx = 1;
    for (int i = 0; i < coef.size(); i++)
    {
        res = (res + (xx * coef[i]) % mod) % mod;
        xx = (xx * x) % mod;
    }
    return (res % mod + mod) % mod;
}

int get(int i)
{
    return f(i);
}

int main(void)
{
    //전체 시간복잡도 O(N) -> TLE
    std::cin >> N >> M;
    coef.resize(M + 1);

    for (int i = 0; i <= M; i++)
    {
        std::cin >> coef[i];
    }

    int min = 2147483647;
    int temp, ans;
    for (int i = 1; i <= N; i++)
    {
        temp = get(i);
        if (min > temp)
        {
            min = temp;
            ans = i;
        }
    }

    std::cout << ans << "\n";

    return 0;
}