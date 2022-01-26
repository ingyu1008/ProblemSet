#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

std::vector<int> par(101010);

int find(int a)
{
    if (a == par[a])
        return a;
    return par[a] = find(par[a]);
}

void uni(int a, int b)
{
    a = find(a);
    b = find(b);
    par[a] = b;
}

std::queue<std::pair<std::pair<ll, ll>, std::pair<ll, ll>>> q;
std::vector<std::pair<ll, ll>> v[20202];

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    ll N, M;
    std::cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        par[i] = i;
    }

    for (ll i = 0, x, y, z, w; i < M; i++)
    {
        std::cin >> x >> y >> z >> w;
        q.push({{x, y}, {z, w}});
    }
    ll a, b;
    std::cin >> a >> b;

    while (!q.empty())
    {
        auto x = q.front().first;
        auto y = q.front().second;
        q.pop();

        v[x.first].push_back({x.second, a * y.first + b * y.second});
        v[x.second].push_back({x.first, a * y.first + b * y.second});
    }

    std::priority_queue<std::pair<ll, ll>> pq;

    for (auto p : v[0])
    {
        pq.push({-p.second, p.first});
    }

    ll res = 0;

    while (!pq.empty())
    {
        ll cost = -pq.top().first;
        ll next = pq.top().second;
        pq.pop();

        if (find(0) == find(next))
            continue;

        res += cost;
        uni(0, next);

        for (auto p : v[next])
        {
            pq.push({-p.second, p.first});
        }
    }

    std::cout << res << "\n";

    return 0;
}