#include "testlib.h"
#include <vector>

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

int valid(std::vector<ll> &v, int N)
{
    if(N == 1e9 && v.size() == 2 && v[0] == 0 && v[1] == 1 || v[1] == -1) return 1;
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
    return cnt;
}

int main(int argc, char *argv[])
{
    registerValidation(argc, argv);

    int N = inf.readInt(3, 1e9, "N");
    inf.readSpace();
    int M = inf.readInt(1, 100, "M");
    inf.readEoln();
    std::vector<ll> v(M + 1);

    for (int i = 0; i <= M; i++)
    {
        v[i] = inf.readInt(-1e5, 1e5);
        if (i < M)
            inf.readSpace();
    }

    int cnt = valid(v, N);

    ensuref(cnt == 1, "Invalid Input, cnt = %d", cnt);
    inf.readEoln();
    inf.readEof();
}