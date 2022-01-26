#include <iostream>

typedef long long ll;

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    ll x, y, h, d;
    while (T--)
    {
        std::cin >> x >> y >> h >> d;

        ll lo = 1;
        ll hi = 1000000;
        ll min = 2147483647;
        while (lo <= hi)
        {
            ll v = (lo + hi) >> 1;
            if (v * v * x * y * (d - x) >= 5 * (d - x) * (d - x) * (x * x + y * y) + v * v * x * x * (h - y))
            {
                min = std::min(min, v);
                hi = v - 1;
            }
            else
            {
                lo = v + 1;
            }
        }
        if (min == 2147483647)
        {
            std::cout << "-1\n";
        }
        else
        {
            std::cout << min << "\n";
        }
    }

    return 0;
}