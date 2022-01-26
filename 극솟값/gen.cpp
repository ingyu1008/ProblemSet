#include "testlib.h"
#include <iostream>

typedef long long ll;

const ll mod = 1e9 + 7;

ll f(std::vector<ll> &v, int x)
{
    if (x == 0)
        return mod;
    ll ret = 0;
    for (ll i = 0, X = 1; i < v.size(); i++, X = (X * x) % mod)
    {
        ret = ((ret + (v[i] * X) % mod) % mod + mod) % mod;
    }
    return ret;
}

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    int N = std::stoi(argv[1]);
    int M = std::stoi(argv[2]);
    std::cout << N << " " << M << "\n";

    while (1)
    {
        std::vector<ll> v(M + 1);
        for (int i = 0; i <= M; i++)
        {
            v[i] = rnd.next(-100000, 100000);
        }

        ll prev = f(v, 0);
        ll now = f(v, 1);
        int cnt = 0;
        for (int i = 2; i < N - 1; i++)
        {
            ll next = f(v, i);
            if (prev >= now && now <= next)
            {
                cnt++;
            }
            prev = now;
            now = next;
        }
        if (prev >= now)
            cnt++;
        if (cnt == 1)
        {
            for (int i = 0; i <= M; i++)
            {
                std::cout << v[i] << " ";
            }
            break;
        }
    }
    std::cout << "\n";
}