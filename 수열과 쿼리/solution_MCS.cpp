#include <iostream>
#include <vector>

typedef long long ll;

struct Node
{
    ll val, lazy, lazy2;
} tree[1 << 19];

void init(ll node, ll l, ll r)
{
    tree[node].val = 0;
    tree[node].lazy = 0;
    tree[node].lazy2 = 0;

    if (l != r)
    {
        ll m = (l + r) >> 1;
        init(node * 2, l, m);
        init(node * 2 + 1, m + 1, r);
    }
}

void lazy(ll node, ll l, ll r)
{
    tree[node].val += tree[node].lazy;
    if (l != r)
    {
        ll m = (l + r) >> 1;
        tree[node * 2].lazy += tree[node].lazy;
        tree[node * 2].lazy2 += tree[node].lazy2;
        tree[node * 2 + 1].lazy += (m - l + 1) * tree[node].lazy2 + tree[node].lazy;
        tree[node * 2 + 1].lazy2 += tree[node].lazy2;
    }
    tree[node].lazy = 0;
    tree[node].lazy2 = 0;
}

void update(ll node, ll l, ll r, ll s, ll e)
{
    lazy(node, l, r);
    if (l > e || r < s)
        return;
    if (l >= s && r <= e)
    {
        tree[node].lazy += l - s + 1;
        tree[node].lazy2++;
        lazy(node, l, r);
        return;
    }

    ll m = (l + r) >> 1;
    update(node * 2, l, m, s, e);
    update(node * 2 + 1, m + 1, r, s, e);
}

ll get(ll node, ll l, ll r, ll x)
{
    lazy(node, l, r);
    if (l > x || r < x)
        return 0;
    if (l == r)
        return tree[node].val;

    ll m = (l + r) >> 1;
    return get(node * 2, l, m, x) + get(node * 2 + 1, m + 1, r, x);
}

ll sparseF[730][40];

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

void initSparseTb()
{
    for (int i = 0; i < 730; i++)
    {
        sparseF[i][0] = i;
        sparseF[i][1] = f(i);
    }
    for (int i = 2; i < 40; i++)
    {
        for (int j = 0; j < 730; j++)
        {
            sparseF[j][i] = sparseF[sparseF[j][i - 1]][i - 1];
        }
    }
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, Q;
    std::cin >> N >> Q;

    init(1, 1, N);
    initSparseTb();

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
            update(1, 1, N, y+1, z);
        }
        else
        {
            std::cin >> y;
            ll ans = get(1, 1, N, y);
            if (ans == 0)
                std::cout << v[y] << "\n";
            else
            {
                ans--;
                z = f(v[y]);
                y = 1;
                while (ans)
                {
                    if (ans & 1)
                        z = sparseF[z][y];
                    y++;
                    ans >>= 1;
                }
                std::cout << z << "\n";
            }
        }
    }

    return 0;
}