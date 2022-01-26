#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

std::vector<std::pair<ll,ll>> v[101010];

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    ll V, E;
    std::cin >> V >> E;

    std::vector<ll> dist(V + 1, 1e18);
    dist[1] = 0;

    for (int i = 0, x, y, z; i < E; i++)
    {
        std::cin >> x >> y >> z;
        v[x].push_back({y,z});
    }

    ll X;
    std::cin >> X;

    std::vector<ll> dist2(V + 1, 1e18);
    dist2[X] = 0;

    std::priority_queue<std::pair<ll, int>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        ll t = -pq.top().first;
        int i = pq.top().second;
        pq.pop();

        if (t > dist[i])
            continue;

        for (auto j : v[i])
        {
            if (dist[j.first] > t + j.second)
            {
                dist[j.first] = t + j.second;
                pq.push({-(t + j.second), j.first});
            }
        }
    }
    pq.push({0, X});

    while (!pq.empty())
    {
        ll t = -pq.top().first;
        int i = pq.top().second;
        pq.pop();

        if (t > dist2[i])
            continue;

        for (auto j : v[i])
        {
            if (dist2[j.first] > t + j.second)
            {
                dist2[j.first] = t + j.second;
                pq.push({-(t + j.second), j.first});
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (dist[X] == 1e18 || dist2[i] == 1e18)
            std::cout << "-1 ";
        else
            std::cout << dist[X] + dist2[i] << " ";
    }

    return 0;
}