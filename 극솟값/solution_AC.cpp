#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

std::vector<int> coef;
std::vector<int> v(2010101);
std::vector<int> toReset;

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
        res = (res + xx * coef[i]) % mod;
        xx = (xx * x) % mod;
    }
    return res;
}

void init()
{
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = 2147483647;
    }
}

void init2()
{
    for (int i = 0; i < toReset.size(); i++)
    {
        v[toReset[i]] = 2147483647;
    }
    toReset.clear();
}

int get(int i)
{
    if (v[i] != 2147483647)
        return v[i];
    toReset.push_back(i);
    return v[i] = f(i);
}

int main(void)
{
    int T;
    std::cin >> T;
    init();     // O(N) 초기화
    while (T--) //전체 시간복잡도 O(TlgN)
    {
        init2(); //O(lgN) 초기화
        std::cin >> N >> M;
        coef.resize(M + 1);

        for (int i = 0; i <= M; i++)
        {
            std::cin >> coef[i];
        }

        v[0] = 2147483647;
        v[N + 1] = 2147483647;

        if (get(1) < get(2))
        {
            std::cout << "1\n";
            continue;
        }
        else if (get(N) < get(N - 1))
        {
            std::cout << N << "\n";
            continue;
        }
        else
        {
            int lo = 1;
            int hi = N;

            while (lo < hi) //O(lgN) 이분탐색
            {
                int m = (lo + hi) >> 1;
                int mm = get(m);
                int ml = get(m - 1);
                int mr = get(m + 1);
                if (ml > mm && mm < mr)
                {
                    std::cout << m << "\n";
                    break;
                }
                else if (ml < mm)
                {
                    hi = m;
                }
                else
                {
                    lo = m;
                }
            }
        }
    }
    return 0;
}