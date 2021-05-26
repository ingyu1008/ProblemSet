#include <iostream>
#include <vector>

#define Ai A[im * n * o * p * q * r * s * t * u * v * w + in * o * p * q * r * s * t * u * v * w + io * p * q * r * s * t * u * v * w + ip * q * r * s * t * u * v * w + iq * r * s * t * u * v * w + ir * s * t * u * v * w + is * t * u * v * w + it * u * v * w + iu * v * w + iv * w + iw]
#define FOR(a, b, c, d, e, f, g, h, i, j, k)                          \
    for (ll im = a; im < m; ++im)                                     \
        for (ll in = b; in < n; ++in)                                 \
            for (ll io = c; io < o; ++io)                             \
                for (ll ip = d; ip < p; ++ip)                         \
                    for (ll iq = e; iq < q; ++iq)                     \
                        for (ll ir = f; ir < r; ++ir)                 \
                            for (ll is = g; is < s; ++is)             \
                                for (ll it = h; it < t; ++it)         \
                                    for (ll iu = i; iu < u; ++iu)     \
                                        for (ll iv = j; iv < v; ++iv) \
                                            for (ll iw = k; iw < w; ++iw)

typedef long long ll;

ll A[10000];

ll m, n, o, p, q, r, s, t, u, v, w;

ll find(ll a, ll b, ll c, ll d, ll e, ll f, ll g, ll h, ll i, ll j, ll k)
{
    if (a < 0 || b < 0 || c < 0 || d < 0 || e < 0 || f < 0 || g < 0 || h < 0 || i < 0 || i < 0 || j < 0 || k < 0)
        return 0;
    return A[a * n * o * p * q * r * s * t * u * v * w + b * o * p * q * r * s * t * u * v * w +
             c * p * q * r * s * t * u * v * w + d * q * r * s * t * u * v * w +
             e * r * s * t * u * v * w + f * s * t * u * v * w + g * t * u * v * w +
             h * u * v * w + i * v * w + j * w + k];
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::cin >> m >> n >> o >> p >> q >> r >> s >> t >> u >> v >> w;
    FOR(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    {
        std::cin >> Ai;
    }

    ll Q;
    std::cin >> Q;

    ll x, a1, b1, c1, d1, e1, f1, g1, h1, i1, j1, a2, b2, c2, d2, e2, f2, g2, h2, i2, j2;
    while (Q--)
    {
        ll sum = 0;
        std::cin >> x >> a1 >> b1 >> c1 >> d1 >> e1 >> f1 >> g1 >> h1 >> i1 >> j1 >> a2 >> b2 >> c2 >> d2 >> e2 >> f2 >> g2 >> h2 >> i2 >> j2;
        a1--, b1--, c1--, d1--, e1--, f1--, g1--, h1--, i1--, j1--, a2--, b2--, c2--, d2--, e2--, f2--, g2--, h2--, i2--, j2--;
        if (x == 1)
        {
            for (int i = 0; i < m; i++)
            {
                sum += find(i, a1, b1, c1, d1, e1, f1, g1, h1, i1, j1) * find(i, a2, b2, c2, d2, e2, f2, g2, h2, i2, j2);
            }
        }
        else if (x == 2)
        {
            for (int i = 0; i < n; i++)
            {
                sum += find(a1, i, b1, c1, d1, e1, f1, g1, h1, i1, j1) * find(a2, i, b2, c2, d2, e2, f2, g2, h2, i2, j2);
            }
        }
        else if (x == 3)
        {
            for (int i = 0; i < o; i++)
            {
                sum += find(a1, b1, i, c1, d1, e1, f1, g1, h1, i1, j1) * find(a2, b2, i, c2, d2, e2, f2, g2, h2, i2, j2);
            }
        }
        else if (x == 4)
        {
            for (int i = 0; i < p; i++)
            {
                sum += find(a1, b1, c1, i, d1, e1, f1, g1, h1, i1, j1) * find(a2, b2, c2, i, d2, e2, f2, g2, h2, i2, j2);
            }
        }
        else if (x == 5)
        {
            for (int i = 0; i < q; i++)
            {
                sum += find(a1, b1, c1, d1, i, e1, f1, g1, h1, i1, j1) * find(a2, b2, c2, d2, i, e2, f2, g2, h2, i2, j2);
            }
        }
        else if (x == 6)
        {
            for (int i = 0; i < r; i++)
            {
                sum += find(a1, b1, c1, d1, e1, i, f1, g1, h1, i1, j1) * find(a2, b2, c2, d2, e2, i, f2, g2, h2, i2, j2);
            }
        }
        else if (x == 7)
        {
            for (int i = 0; i < s; i++)
            {
                sum += find(a1, b1, c1, d1, e1, f1, i, g1, h1, i1, j1) * find(a2, b2, c2, d2, e2, f2, i, g2, h2, i2, j2);
            }
        }
        else if (x == 8)
        {
            for (int i = 0; i < t; i++)
            {
                sum += find(a1, b1, c1, d1, e1, f1, g1, i, h1, i1, j1) * find(a2, b2, c2, d2, e2, f2, g2, i, h2, i2, j2);
            }
        }
        else if (x == 9)
        {
            for (int i = 0; i < u; i++)
            {
                sum += find(a1, b1, c1, d1, e1, f1, g1, h1, i, i1, j1) * find(a2, b2, c2, d2, e2, f2, g2, h2, i, i2, j2);
            }
        }
        else if (x == 10)
        {
            for (int i = 0; i < v; i++)
            {
                sum += find(a1, b1, c1, d1, e1, f1, g1, h1, i1, i, j1) * find(a2, b2, c2, d2, e2, f2, g2, h2, i2, i, j2);
            }
        }
        else if (x == 11)
        {
            for (int i = 0; i < w; i++)
            {
                sum += find(a1, b1, c1, d1, e1, f1, g1, h1, i1, j1, i) * find(a2, b2, c2, d2, e2, f2, g2, h2, i2, j2, i);
            }
        }
        std::cout << sum << "\n";
    }

    return 0;
}