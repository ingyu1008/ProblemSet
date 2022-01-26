#include "testlib.h"
#include <vector>
#include <iostream>

typedef long long ll;

int N, M;
std::vector<int> v;
ll mod = 1e9 + 7;

ll f(ll x)
{
    if (x == 0)
        return 2147483647;
    if (x == N + 1)
        return 2147483647;
    ll res = 0;
    ll xx = 1;
    for (int i = 0; i < v.size(); i++)
    {
        res = (res + (xx * v[i]) % mod) % mod;
        xx = (xx * x) % mod;
    }
    return (res % mod + mod) % mod;
}

inline int readAndCheckAnswer(InStream &in)
{
    int out = in.readInt();

    if (out < 1 || out > N)
    {
        in.quitf(_wa, "Answer is not valid");
    }

    int left = f(out - 1);
    int me = f(out);
    int right = f(out + 1);
    if (left < me || me > right)
    {
        in.quitf(_wa, "{an} has no local minimum at n = %d", out);
    }
    return out;
}

int main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);

    N = inf.readInt();
    M = inf.readInt();
    v.resize(M + 1);

    for (int i = 0; i <= M; i++)
    {
        v[i] = inf.readInt();
    }

    readAndCheckAnswer(ouf);
    quitf(_ok, "Accepted");
}