#include <iostream>
#include <vector>

typedef long long ll;

ll f(ll x)
{
    ll ans = 0;
    ll y;
    while (x)
    {
        y = x % 10;
        ans += y * y;
        x /= 10;
    }
    return ans;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, Q;
    std::cin >> N >> Q;

    std::vector<ll> v(N + 1);
    for (int i = 1; i <= N; i++)
    {
        std::cin >> v[i];
    }
    ll x, y, z;
    while (Q--)
    {
        std::cin >> x;
        if (x == 1)
        {
            std::cin >> y >> z;
            for (ll i = y; i <= z; i++)
            {
                for (ll j = 0; j < i - y; j++)
                {
                    v[i] = f(v[i]);
                }
            }
        }
        else
        {
            std::cin >> y;
            std::cout << v[y] << "\n";
        }
    }

    return 0;
}